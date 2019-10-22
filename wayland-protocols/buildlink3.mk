# $NetBSD$

BUILDLINK_TREE+=        wayland-protocols

.if !defined(WAYLAND_PROTOCOLS_BUILDLINK3_MK)
WAYLAND_PROTOCOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wayland-protocols+=    wayland-protocols>=1.1.0
BUILDLINK_PKGSRCDIR.wayland-protocols?=      ../../wip/wayland-protocols
.endif # WAYLAND_PROTOCOLS_BUILDLINK3_MK

BUILDLINK_TREE+=        -wayland-protocols
