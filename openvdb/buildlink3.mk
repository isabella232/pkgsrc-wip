# $NetBSD$

BUILDLINK_TREE+=	openvdb

.if !defined(OPENVDB_BUILDLINK3_MK)
OPENVDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openvdb+=	openvdb>=7.0.0
BUILDLINK_PKGSRCDIR.openvdb?=	../../wip/openvdb
.endif	# OPENVDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-openvdb
