# $NetBSD: Makefile,v 1.5 2012/11/13 22:25:47 othyro Exp $
#

DISTNAME=	rsget.pl-11838
CATEGORIES=	net
MASTER_SITES=	http://rsget.pl/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://rsget.pl/
COMMENT=	Perl application designed to retrieve files from download services
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake perl:run

DEPENDS=	p5-WWW-Curl>=4.11:../../www/p5-WWW-Curl
DEPENDS+=	p5-URI>=1.53:../../www/p5-URI
DEPENDS+=	p5-GD>=2.44nb3:../../graphics/p5-GD
DEPENDS+=	tesseract>=2.04nb2:../../graphics/tesseract
DEPENDS+=	p5-Term-Size>=0.207:../../devel/p5-Term-Size
DEPENDS+=	p5-PerlMagick>=6.6.1.5nb4:../../graphics/p5-PerlMagick
DEPENDS+=	p5-Crypt-Blowfish>=2.12:../../security/p5-Crypt-Blowfish
DEPENDS+=	p5-Crypt-Rijndael>=1.09:../../security/p5-Crypt-Rijndael

INSTALL_MAKE_FLAGS=	PERL=${PREFIX}/bin/perl

INSTALLATION_DIRS=	share/doc/rsget.pl

USE_LANGUAGES=	# none

post-install:
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/share/doc/rsget.pl

.include "../../mk/bsd.pkg.mk"
