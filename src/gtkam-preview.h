/* gtkam-preview.h
 *
 * Copyright (C) 2001 Lutz M�ller <urc8@rz.uni-karlsruhe.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details. 
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GTKAM_PREVIEW_H__
#define __GTKAM_PREVIEW_H__

#include <gphoto2/gphoto2-camera.h>
#include <gtk/gtkdialog.h>

#define GTKAM_TYPE_PREVIEW  (gtkam_preview_get_type ())
#define GTKAM_PREVIEW(o)    (GTK_CHECK_CAST((o),GTKAM_TYPE_PREVIEW,GtkamPreview))
#define GTKAM_IS_PREVIEW(o) (GTK_CHECK_TYPE((o),GTKAM_TYPE_PREVIEW))

typedef struct _GtkamPreview        GtkamPreview;
typedef struct _GtkamPreviewPrivate GtkamPreviewPrivate;
typedef struct _GtkamPreviewClass   GtkamPreviewClass;

struct _GtkamPreview
{
	GtkDialog parent;

	GtkamPreviewPrivate *priv;
};

struct _GtkamPreviewClass
{
	GtkDialogClass parent_class;

	/* Signals */
	void (* captured) (GtkamPreview *preview, const gchar *path);
};

GtkType    gtkam_preview_get_type (void);
GtkWidget *gtkam_preview_new      (Camera *camera);

#endif /* __GTKAM_PREVIEW_H__ */