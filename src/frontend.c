#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gphoto2.h>
#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>

#include "globals.h"
#include "gtkiconlist.h"
#include "interface.h"
#include "frontend.h"
#include "support.h"
#include "util.h"
#include "gtkam-close.h"

int
frontend_message (Camera *camera, char *message)
{
	GtkWidget *dialog;

	dialog = gtkam_close_new (message, NULL);
	gtk_widget_show (dialog);

	return (GP_OK);
}

int frontend_confirm(Camera *camera, char *message) {

	GtkWidget *confirm = create_confirm_window();
	GtkWidget *label   = (GtkWidget*) lookup_widget(confirm, "message");
	GtkWidget *yes     = (GtkWidget*) lookup_widget(confirm, "yes");
	GtkWidget *no      = (GtkWidget*) lookup_widget(confirm, "no");
	int ret = 0;

	gtk_label_set_text(GTK_LABEL(label), message);
	ret = wait_for_hide(confirm, yes, no);

	if (ret)
		gtk_widget_destroy(confirm);

	return (ret);
}