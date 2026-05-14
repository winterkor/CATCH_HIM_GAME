#ifndef COMPAT_H
#define COMPAT_H

#ifdef _WIN32
  #include <conio.h>
  #include <windows.h>
  #define CLEAR_CMD "cls"
  #define PAUSE_CMD "pause"
  static void terminal_reset(void) { /* nothing to do on Windows */ }
#else
  #include <unistd.h>
  #include <termios.h>
  #include <time.h>

  /* Force the terminal into a known-good canonical state. Called at startup
     and on exit so a previous crashed run can't leave us with ICRNL or ECHO
     disabled when scanf later needs them. */
  static void terminal_reset(void) {
      struct termios t;
      if (tcgetattr(STDIN_FILENO, &t) == 0) {
          t.c_iflag |= ICRNL;
          t.c_lflag |= ICANON | ECHO;
          tcsetattr(STDIN_FILENO, TCSANOW, &t);
      }
  }

  static int getch(void) {
      struct termios oldt, newt;
      int ch;
      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);  /* raw char read, no echo */
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      ch = getchar();
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      if (ch == '\n') ch = '\r';         /* normalize Enter to CR (== ENTER macro) */
      return ch;
  }

  static void Sleep(unsigned int ms) {
      struct timespec ts;
      ts.tv_sec = ms / 1000;
      ts.tv_nsec = (ms % 1000) * 1000000L;
      nanosleep(&ts, NULL);
  }

  #define CLEAR_CMD "clear"
  #define PAUSE_CMD "read -n 1 -s -r -p 'Press any key to continue...'; echo"
#endif

#endif
