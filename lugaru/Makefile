# $NetBSD$

DISTNAME=	lugaru-${VERSION}
VERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/osslugaru/lugaru/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Open source release of the game from Wolfire
HOMEPAGE=	https://osslugaru.gitlab.io/
LICENSE=	gnu-gpl-v2 AND cc-by-sa-v3.0 AND cc-by-sa-v4.0

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DSYSTEM_INSTALL=ON

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
