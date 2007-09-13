#ifndef __G_VFS_READ_REQUEST_H__
#define __G_VFS_READ_REQUEST_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define G_TYPE_VFS_READ_REQUEST         (g_vfs_read_request_get_type ())
#define G_VFS_READ_REQUEST(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), G_TYPE_VFS_READ_REQUEST, GVfsReadRequest))
#define G_VFS_READ_REQUEST_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), G_TYPE_VFS_READ_REQUEST, GVfsReadRequestClass))
#define G_IS_VFS_READ_REQUEST(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), G_TYPE_VFS_READ_REQUEST))
#define G_IS_VFS_READ_REQUEST_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), G_TYPE_VFS_READ_REQUEST))
#define G_VFS_READ_REQUEST_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), G_TYPE_VFS_READ_REQUEST, GVfsReadRequestClass))

typedef struct _GVfsReadRequest        GVfsReadRequest;
typedef struct _GVfsReadRequestClass   GVfsReadRequestClass;

struct _GVfsReadRequest
{
  GObject parent_instance;

  int fd;
  int remote_fd;
};

struct _GVfsReadRequestClass
{
  GObjectClass parent_class;

  /* vtable */
};

GType g_vfs_read_request_get_type (void) G_GNUC_CONST;

GVfsReadRequest *g_vfs_read_request_new (GError **error);
int g_vfs_read_request_get_fd (GVfsReadRequest *read_request);
int g_vfs_read_request_get_remote_fd (GVfsReadRequest *read_request);
void g_vfs_read_request_close_remote_fd (GVfsReadRequest *read_request);

G_END_DECLS

#endif /* __G_VFS_READ_REQUEST_H__ */
