#include <ncurses.h>

int main() {
    // Initialisation de ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Création d'une première fenêtre
    WINDOW *win1 = newwin(10, 30, 5, 5); // Créer une fenêtre 10x30 à la position (5,5)
    box(win1, 0, 0); // Dessiner une bordure autour de la fenêtre
    mvwprintw(win1, 1, 1, "Fenetre 1"); // Afficher un message dans la fenêtre
    wrefresh(win1); // Rafraîchir la fenêtre
    getch(); // Attendre une touche

    // Libérer la première fenêtre
    delwin(win1);

    // Création d'une deuxième fenêtre
    WINDOW *win2 = newwin(5, 20, 8, 8); // Créer une fenêtre 5x20 à la position (8,8)
    box(win2, 0, 0);
    mvwprintw(win2, 1, 1, "Fenetre 2");
    wrefresh(win2);
    getch();

    // Libérer la deuxième fenêtre
    delwin(win2);

    // Création d'une troisième fenêtre
    WINDOW *win3 = newwin(15, 40, 3, 3); // Créer une fenêtre 15x40 à la position (3,3)
    box(win3, 0, 0);
    mvwprintw(win3, 1, 1, "Fenetre 3");
    wrefresh(win3);
    getch();

    // Libérer la troisième fenêtre
    delwin(win3);

    // Libération de ncurses
    endwin();

    return 0;
}
