# $NetBSD: buildlink3.mk,v 1.3 2008/08/07 19:03:31 htepper Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENSC_BUILDLINK3_MK:=	${OPENSC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	opensc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopensc}
BUILDLINK_PACKAGES+=	opensc

.if !empty(OPENSC_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.opensc+=	opensc>=0.11.5
BUILDLINK_PKGSRCDIR.opensc?=	../../wip/opensc
.endif	# OPENSC_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
