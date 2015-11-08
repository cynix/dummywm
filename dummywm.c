#include <unistd.h>
#include <X11/Xlib.h>

int main(void)
{
	daemon(0, 0);

	Display* display = XOpenDisplay(0);
	if (!display) return 1;

	int screen = DefaultScreen(display);
	int w = DisplayWidth(display, screen);
	int h = DisplayHeight(display, screen);

	Window window, root = RootWindow(display, screen);
	XSelectInput(display, root, SubstructureRedirectMask);

	XEvent event;
	while (!XNextEvent(display, &event)) {
		if (event.type == MapRequest && (window = event.xmaprequest.window)) {
			XMoveResizeWindow(display, window, 0, 0, w, h);
			XMapWindow(display, window);
			XSetInputFocus(display, window, RevertToPointerRoot, CurrentTime);
			XFlush(display);
		}
	}

	return 0;
}
