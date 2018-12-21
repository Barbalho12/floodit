#include "include/interface.h"
#include <gtk/gtk.h>
/*Compilar Linux: gcc loadGame.c interface.c color.c table.c file.c controle.c -o loadGame `pkg-config --cflags --libs gtk+-3.0`*/

/*Windows: gcc loadGame.c interface.c color.c table.c file.c controle.c -o loadGame -mms-bitfields -IC:/gtk3/include/gtk-3.0 
-IC:/gtk3/include/cairo -IC:/gtk3/include/pango-1.0 -IC:/gtk3/include/atk-1.0 -IC:/gtk3/include/cairo -IC:/gtk3/include/pixman-1 
-IC:/gtk3/include -IC:/gtk3/include/freetype2 -IC:/gtk3/include -IC:/gtk3/include/libpng15 -IC:/gtk3/include/gdk-pixbuf-2.0 
-IC:/gtk3/include/libpng15 -IC:/gtk3/include/glib-2.0 -IC:/gtk3/lib/glib-2.0/include -LC:/gtk3/lib -lgtk-3 -lgdk-3 -lgdi32 -limm32 
-lshell32 -lole32 -Wl,-luuid -lpangocairo-1.0 -lpangoft2-1.0 -lfreetype -lfontconfig -lpangowin32-1.0 -lgdi32 -lpango-1.0 -lm 
-latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 -lintl*/


/*gcc loadGame.c interface.c color.c table.c file.c controle.c -o loadGame -mms-bitfields -IC:/gtk3/include/gtk-3.0 -IC:/gtk3/include/cairo 
-IC:/gtk3/include/pango-1.0 -IC:/gtk3/include/atk-1.0 -IC:/gtk3/include/cairo -IC:/gtk3/include -IC:/gtk3/include/gdk-pixbuf-2.0 
-IC:/gtk3/include/libpng15 -IC:/gtk3/include/glib-2.0 -IC:/gtk3/lib/glib-2.0/include -LC:/gtk3/lib -lgtk-3 -lgobject-2.0 -lglib-2.0*/

int main(int argc, char*argv[]){
	
	gtk_init(&argc, &argv);
	
    Floodit flood; 
    Interface jogo; 
	
	flood.orderMatriz = 14;
	flood.qtdRodada = 25;
	
	montaMatriz(&flood);
	flood.rodada = 0;
	
    jogo.flood = &flood;
	
	interfaceInit(&jogo); 
    return 0;
}
