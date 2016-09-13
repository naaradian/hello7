#include "gps.h"
//#include "omgps.h"
//#include "xpm_image.h"

#define NAN  99

int				g_init_status;
//map_view_t		g_view;
//cfg_t*			g_cfg = NULL;
//context_t		g_context;

/* protected by gdk global lock: LOCK_UI/UNLOCK_UI() */
gps_data_t		g_gpsdata;

char			g_ubx_receiver_versions[64];

/*
GtkWidget *		g_window = NULL;

TAB_ID_T		g_tab_id = TAB_ID_MAIN_VIEW;
menu_item_t		g_menus[TAB_ID_MAX];
ctx_tab_item_t	g_ctx_panes[CTX_ID_MAX];
GtkWidget *		g_ctx_containers[CTX_ID_MAX];

xpm_t			g_xpm_images[XPM_ID_MAX];

pthread_t		g_gdk_lock_owner = 0;
   */
   
void init_gpsdata(gps_data_t *gd)
{
	gd->latlon_valid = FALSE;
	gd->height_valid = FALSE;
	gd->vel_valid = FALSE;
	gd->svinfo_valid = FALSE;

	gd->llh_itow = 0;
	gd->lat = NAN;
	gd->lon = NAN;
	gd->height = NAN;
	gd->hacc = NAN;
	gd->vacc = NAN;

	gd->speed_2d = NAN;
	gd->heading_2d = NAN;
	gd->vel_down = NAN;

	gd->sv_in_use = 0;
	gd->sv_get_signal = 0;
	gd->sv_channel_count = 0;
}   