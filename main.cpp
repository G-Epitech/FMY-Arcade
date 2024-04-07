/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** main
*/

#include <ncurses.h>

int main() {
    // Initialisation de ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Activer le support de la souris
    mousemask(ALL_MOUSE_EVENTS, NULL);

    printw("Utilisez la souris pour cliquer :\n");
    printw("Appuyez sur 'q' pour quitter.\n");

    // Boucle pour récupérer les événements de la souris
    while (true) {
        int ch = getch();

        if (ch == 'q') {
            break;
        }

        // Vérifier s'il y a des événements de souris
        MEVENT event;
        if (getmouse(&event) == OK) {
            // Vérifier si un clic de souris a eu lieu
            if (event.bstate & BUTTON1_CLICKED) {
                // Afficher les coordonnées du clic de souris
                printw("Clic de souris à la position : %d, %d\n", event.x, event.y);
            }
        }

        // Rafraîchir l'écran
        refresh();
    }

    // Fermeture de ncurses
    endwin();

    return 0;
}
