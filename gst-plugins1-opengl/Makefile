# $NetBSD: Makefile,v 1.2 2020/03/08 16:50:41 wiz Exp $

GST_PLUGINS1_NAME=	opengl
GST_PLUGINS1_FLAGS=	egl
GST_PLUGINS1_DIRS=	ext/gl

LDFLAGS+=		${COMPILER_RPATH_FLAG}${X11BASE}/lib -L${X11BASE}/lib

.include "../../multimedia/gst-plugins1-base/Makefile.common"

.include "../../wip/gst-plugins1-gl/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
