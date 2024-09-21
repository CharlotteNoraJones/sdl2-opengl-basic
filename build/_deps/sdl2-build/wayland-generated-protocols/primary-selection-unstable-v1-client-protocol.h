/* Generated by wayland-scanner 1.20.0 */

#ifndef WP_PRIMARY_SELECTION_UNSTABLE_V1_CLIENT_PROTOCOL_H
#define WP_PRIMARY_SELECTION_UNSTABLE_V1_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_wp_primary_selection_unstable_v1 The wp_primary_selection_unstable_v1 protocol
 * Primary selection protocol
 *
 * @section page_desc_wp_primary_selection_unstable_v1 Description
 *
 * This protocol provides the ability to have a primary selection device to
 * match that of the X server. This primary selection is a shortcut to the
 * common clipboard selection, where text just needs to be selected in order
 * to allow copying it elsewhere. The de facto way to perform this action
 * is the middle mouse button, although it is not limited to this one.
 *
 * Clients wishing to honor primary selection should create a primary
 * selection source and set it as the selection through
 * wp_primary_selection_device.set_selection whenever the text selection
 * changes. In order to minimize calls in pointer-driven text selection,
 * it should happen only once after the operation finished. Similarly,
 * a NULL source should be set when text is unselected.
 *
 * wp_primary_selection_offer objects are first announced through the
 * wp_primary_selection_device.data_offer event. Immediately after this event,
 * the primary data offer will emit wp_primary_selection_offer.offer events
 * to let know of the mime types being offered.
 *
 * When the primary selection changes, the client with the keyboard focus
 * will receive wp_primary_selection_device.selection events. Only the client
 * with the keyboard focus will receive such events with a non-NULL
 * wp_primary_selection_offer. Across keyboard focus changes, previously
 * focused clients will receive wp_primary_selection_device.events with a
 * NULL wp_primary_selection_offer.
 *
 * In order to request the primary selection data, the client must pass
 * a recent serial pertaining to the press event that is triggering the
 * operation, if the compositor deems the serial valid and recent, the
 * wp_primary_selection_source.send event will happen in the other end
 * to let the transfer begin. The client owning the primary selection
 * should write the requested data, and close the file descriptor
 * immediately.
 *
 * If the primary selection owner client disappeared during the transfer,
 * the client reading the data will receive a
 * wp_primary_selection_device.selection event with a NULL
 * wp_primary_selection_offer, the client should take this as a hint
 * to finish the reads related to the no longer existing offer.
 *
 * The primary selection owner should be checking for errors during
 * writes, merely cancelling the ongoing transfer if any happened.
 *
 * @section page_ifaces_wp_primary_selection_unstable_v1 Interfaces
 * - @subpage page_iface_zwp_primary_selection_device_manager_v1 - X primary selection emulation
 * - @subpage page_iface_zwp_primary_selection_device_v1 - 
 * - @subpage page_iface_zwp_primary_selection_offer_v1 - offer to transfer primary selection contents
 * - @subpage page_iface_zwp_primary_selection_source_v1 - offer to replace the contents of the primary selection
 * @section page_copyright_wp_primary_selection_unstable_v1 Copyright
 * <pre>
 *
 * Copyright © 2015, 2016 Red Hat
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * </pre>
 */
struct wl_seat;
struct zwp_primary_selection_device_manager_v1;
struct zwp_primary_selection_device_v1;
struct zwp_primary_selection_offer_v1;
struct zwp_primary_selection_source_v1;

#ifndef ZWP_PRIMARY_SELECTION_DEVICE_MANAGER_V1_INTERFACE
#define ZWP_PRIMARY_SELECTION_DEVICE_MANAGER_V1_INTERFACE
/**
 * @page page_iface_zwp_primary_selection_device_manager_v1 zwp_primary_selection_device_manager_v1
 * @section page_iface_zwp_primary_selection_device_manager_v1_desc Description
 *
 * The primary selection device manager is a singleton global object that
 * provides access to the primary selection. It allows to create
 * wp_primary_selection_source objects, as well as retrieving the per-seat
 * wp_primary_selection_device objects.
 * @section page_iface_zwp_primary_selection_device_manager_v1_api API
 * See @ref iface_zwp_primary_selection_device_manager_v1.
 */
/**
 * @defgroup iface_zwp_primary_selection_device_manager_v1 The zwp_primary_selection_device_manager_v1 interface
 *
 * The primary selection device manager is a singleton global object that
 * provides access to the primary selection. It allows to create
 * wp_primary_selection_source objects, as well as retrieving the per-seat
 * wp_primary_selection_device objects.
 */
extern const struct wl_interface zwp_primary_selection_device_manager_v1_interface;
#endif
#ifndef ZWP_PRIMARY_SELECTION_DEVICE_V1_INTERFACE
#define ZWP_PRIMARY_SELECTION_DEVICE_V1_INTERFACE
/**
 * @page page_iface_zwp_primary_selection_device_v1 zwp_primary_selection_device_v1
 * @section page_iface_zwp_primary_selection_device_v1_api API
 * See @ref iface_zwp_primary_selection_device_v1.
 */
/**
 * @defgroup iface_zwp_primary_selection_device_v1 The zwp_primary_selection_device_v1 interface
 */
extern const struct wl_interface zwp_primary_selection_device_v1_interface;
#endif
#ifndef ZWP_PRIMARY_SELECTION_OFFER_V1_INTERFACE
#define ZWP_PRIMARY_SELECTION_OFFER_V1_INTERFACE
/**
 * @page page_iface_zwp_primary_selection_offer_v1 zwp_primary_selection_offer_v1
 * @section page_iface_zwp_primary_selection_offer_v1_desc Description
 *
 * A wp_primary_selection_offer represents an offer to transfer the contents
 * of the primary selection clipboard to the client. Similar to
 * wl_data_offer, the offer also describes the mime types that the data can
 * be converted to and provides the mechanisms for transferring the data
 * directly to the client.
 * @section page_iface_zwp_primary_selection_offer_v1_api API
 * See @ref iface_zwp_primary_selection_offer_v1.
 */
/**
 * @defgroup iface_zwp_primary_selection_offer_v1 The zwp_primary_selection_offer_v1 interface
 *
 * A wp_primary_selection_offer represents an offer to transfer the contents
 * of the primary selection clipboard to the client. Similar to
 * wl_data_offer, the offer also describes the mime types that the data can
 * be converted to and provides the mechanisms for transferring the data
 * directly to the client.
 */
extern const struct wl_interface zwp_primary_selection_offer_v1_interface;
#endif
#ifndef ZWP_PRIMARY_SELECTION_SOURCE_V1_INTERFACE
#define ZWP_PRIMARY_SELECTION_SOURCE_V1_INTERFACE
/**
 * @page page_iface_zwp_primary_selection_source_v1 zwp_primary_selection_source_v1
 * @section page_iface_zwp_primary_selection_source_v1_desc Description
 *
 * The source side of a wp_primary_selection_offer, it provides a way to
 * describe the offered data and respond to requests to transfer the
 * requested contents of the primary selection clipboard.
 * @section page_iface_zwp_primary_selection_source_v1_api API
 * See @ref iface_zwp_primary_selection_source_v1.
 */
/**
 * @defgroup iface_zwp_primary_selection_source_v1 The zwp_primary_selection_source_v1 interface
 *
 * The source side of a wp_primary_selection_offer, it provides a way to
 * describe the offered data and respond to requests to transfer the
 * requested contents of the primary selection clipboard.
 */
extern const struct wl_interface zwp_primary_selection_source_v1_interface;
#endif

#define ZWP_PRIMARY_SELECTION_DEVICE_MANAGER_V1_CREATE_SOURCE 0
#define ZWP_PRIMARY_SELECTION_DEVICE_MANAGER_V1_GET_DEVICE 1
#define ZWP_PRIMARY_SELECTION_DEVICE_MANAGER_V1_DESTROY 2


/**
 * @ingroup iface_zwp_primary_selection_device_manager_v1
 */
#define ZWP_PRIMARY_SELECTION_DEVICE_MANAGER_V1_CREATE_SOURCE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_primary_selection_device_manager_v1
 */
#define ZWP_PRIMARY_SELECTION_DEVICE_MANAGER_V1_GET_DEVICE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_primary_selection_device_manager_v1
 */
#define ZWP_PRIMARY_SELECTION_DEVICE_MANAGER_V1_DESTROY_SINCE_VERSION 1

/** @ingroup iface_zwp_primary_selection_device_manager_v1 */
static inline void
zwp_primary_selection_device_manager_v1_set_user_data(struct zwp_primary_selection_device_manager_v1 *zwp_primary_selection_device_manager_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwp_primary_selection_device_manager_v1, user_data);
}

/** @ingroup iface_zwp_primary_selection_device_manager_v1 */
static inline void *
zwp_primary_selection_device_manager_v1_get_user_data(struct zwp_primary_selection_device_manager_v1 *zwp_primary_selection_device_manager_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwp_primary_selection_device_manager_v1);
}

static inline uint32_t
zwp_primary_selection_device_manager_v1_get_version(struct zwp_primary_selection_device_manager_v1 *zwp_primary_selection_device_manager_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zwp_primary_selection_device_manager_v1);
}

/**
 * @ingroup iface_zwp_primary_selection_device_manager_v1
 *
 * Create a new primary selection source.
 */
static inline struct zwp_primary_selection_source_v1 *
zwp_primary_selection_device_manager_v1_create_source(struct zwp_primary_selection_device_manager_v1 *zwp_primary_selection_device_manager_v1)
{
	struct wl_proxy *id;

	id = wl_proxy_marshal_flags((struct wl_proxy *) zwp_primary_selection_device_manager_v1,
			 ZWP_PRIMARY_SELECTION_DEVICE_MANAGER_V1_CREATE_SOURCE, &zwp_primary_selection_source_v1_interface, wl_proxy_get_version((struct wl_proxy *) zwp_primary_selection_device_manager_v1), 0, NULL);

	return (struct zwp_primary_selection_source_v1 *) id;
}

/**
 * @ingroup iface_zwp_primary_selection_device_manager_v1
 *
 * Create a new data device for a given seat.
 */
static inline struct zwp_primary_selection_device_v1 *
zwp_primary_selection_device_manager_v1_get_device(struct zwp_primary_selection_device_manager_v1 *zwp_primary_selection_device_manager_v1, struct wl_seat *seat)
{
	struct wl_proxy *id;

	id = wl_proxy_marshal_flags((struct wl_proxy *) zwp_primary_selection_device_manager_v1,
			 ZWP_PRIMARY_SELECTION_DEVICE_MANAGER_V1_GET_DEVICE, &zwp_primary_selection_device_v1_interface, wl_proxy_get_version((struct wl_proxy *) zwp_primary_selection_device_manager_v1), 0, NULL, seat);

	return (struct zwp_primary_selection_device_v1 *) id;
}

/**
 * @ingroup iface_zwp_primary_selection_device_manager_v1
 *
 * Destroy the primary selection device manager.
 */
static inline void
zwp_primary_selection_device_manager_v1_destroy(struct zwp_primary_selection_device_manager_v1 *zwp_primary_selection_device_manager_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_primary_selection_device_manager_v1,
			 ZWP_PRIMARY_SELECTION_DEVICE_MANAGER_V1_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_primary_selection_device_manager_v1), WL_MARSHAL_FLAG_DESTROY);
}

/**
 * @ingroup iface_zwp_primary_selection_device_v1
 * @struct zwp_primary_selection_device_v1_listener
 */
struct zwp_primary_selection_device_v1_listener {
	/**
	 * introduce a new wp_primary_selection_offer
	 *
	 * Introduces a new wp_primary_selection_offer object that may be
	 * used to receive the current primary selection. Immediately
	 * following this event, the new wp_primary_selection_offer object
	 * will send wp_primary_selection_offer.offer events to describe
	 * the offered mime types.
	 */
	void (*data_offer)(void *data,
			   struct zwp_primary_selection_device_v1 *zwp_primary_selection_device_v1,
			   struct zwp_primary_selection_offer_v1 *offer);
	/**
	 * advertise a new primary selection
	 *
	 * The wp_primary_selection_device.selection event is sent to
	 * notify the client of a new primary selection. This event is sent
	 * after the wp_primary_selection.data_offer event introducing this
	 * object, and after the offer has announced its mimetypes through
	 * wp_primary_selection_offer.offer.
	 *
	 * The data_offer is valid until a new offer or NULL is received or
	 * until the client loses keyboard focus. The client must destroy
	 * the previous selection data_offer, if any, upon receiving this
	 * event.
	 */
	void (*selection)(void *data,
			  struct zwp_primary_selection_device_v1 *zwp_primary_selection_device_v1,
			  struct zwp_primary_selection_offer_v1 *id);
};

/**
 * @ingroup iface_zwp_primary_selection_device_v1
 */
static inline int
zwp_primary_selection_device_v1_add_listener(struct zwp_primary_selection_device_v1 *zwp_primary_selection_device_v1,
					     const struct zwp_primary_selection_device_v1_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) zwp_primary_selection_device_v1,
				     (void (**)(void)) listener, data);
}

#define ZWP_PRIMARY_SELECTION_DEVICE_V1_SET_SELECTION 0
#define ZWP_PRIMARY_SELECTION_DEVICE_V1_DESTROY 1

/**
 * @ingroup iface_zwp_primary_selection_device_v1
 */
#define ZWP_PRIMARY_SELECTION_DEVICE_V1_DATA_OFFER_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_primary_selection_device_v1
 */
#define ZWP_PRIMARY_SELECTION_DEVICE_V1_SELECTION_SINCE_VERSION 1

/**
 * @ingroup iface_zwp_primary_selection_device_v1
 */
#define ZWP_PRIMARY_SELECTION_DEVICE_V1_SET_SELECTION_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_primary_selection_device_v1
 */
#define ZWP_PRIMARY_SELECTION_DEVICE_V1_DESTROY_SINCE_VERSION 1

/** @ingroup iface_zwp_primary_selection_device_v1 */
static inline void
zwp_primary_selection_device_v1_set_user_data(struct zwp_primary_selection_device_v1 *zwp_primary_selection_device_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwp_primary_selection_device_v1, user_data);
}

/** @ingroup iface_zwp_primary_selection_device_v1 */
static inline void *
zwp_primary_selection_device_v1_get_user_data(struct zwp_primary_selection_device_v1 *zwp_primary_selection_device_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwp_primary_selection_device_v1);
}

static inline uint32_t
zwp_primary_selection_device_v1_get_version(struct zwp_primary_selection_device_v1 *zwp_primary_selection_device_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zwp_primary_selection_device_v1);
}

/**
 * @ingroup iface_zwp_primary_selection_device_v1
 *
 * Replaces the current selection. The previous owner of the primary
 * selection will receive a wp_primary_selection_source.cancelled event.
 *
 * To unset the selection, set the source to NULL.
 */
static inline void
zwp_primary_selection_device_v1_set_selection(struct zwp_primary_selection_device_v1 *zwp_primary_selection_device_v1, struct zwp_primary_selection_source_v1 *source, uint32_t serial)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_primary_selection_device_v1,
			 ZWP_PRIMARY_SELECTION_DEVICE_V1_SET_SELECTION, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_primary_selection_device_v1), 0, source, serial);
}

/**
 * @ingroup iface_zwp_primary_selection_device_v1
 *
 * Destroy the primary selection device.
 */
static inline void
zwp_primary_selection_device_v1_destroy(struct zwp_primary_selection_device_v1 *zwp_primary_selection_device_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_primary_selection_device_v1,
			 ZWP_PRIMARY_SELECTION_DEVICE_V1_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_primary_selection_device_v1), WL_MARSHAL_FLAG_DESTROY);
}

/**
 * @ingroup iface_zwp_primary_selection_offer_v1
 * @struct zwp_primary_selection_offer_v1_listener
 */
struct zwp_primary_selection_offer_v1_listener {
	/**
	 * advertise offered mime type
	 *
	 * Sent immediately after creating announcing the
	 * wp_primary_selection_offer through
	 * wp_primary_selection_device.data_offer. One event is sent per
	 * offered mime type.
	 */
	void (*offer)(void *data,
		      struct zwp_primary_selection_offer_v1 *zwp_primary_selection_offer_v1,
		      const char *mime_type);
};

/**
 * @ingroup iface_zwp_primary_selection_offer_v1
 */
static inline int
zwp_primary_selection_offer_v1_add_listener(struct zwp_primary_selection_offer_v1 *zwp_primary_selection_offer_v1,
					    const struct zwp_primary_selection_offer_v1_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) zwp_primary_selection_offer_v1,
				     (void (**)(void)) listener, data);
}

#define ZWP_PRIMARY_SELECTION_OFFER_V1_RECEIVE 0
#define ZWP_PRIMARY_SELECTION_OFFER_V1_DESTROY 1

/**
 * @ingroup iface_zwp_primary_selection_offer_v1
 */
#define ZWP_PRIMARY_SELECTION_OFFER_V1_OFFER_SINCE_VERSION 1

/**
 * @ingroup iface_zwp_primary_selection_offer_v1
 */
#define ZWP_PRIMARY_SELECTION_OFFER_V1_RECEIVE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_primary_selection_offer_v1
 */
#define ZWP_PRIMARY_SELECTION_OFFER_V1_DESTROY_SINCE_VERSION 1

/** @ingroup iface_zwp_primary_selection_offer_v1 */
static inline void
zwp_primary_selection_offer_v1_set_user_data(struct zwp_primary_selection_offer_v1 *zwp_primary_selection_offer_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwp_primary_selection_offer_v1, user_data);
}

/** @ingroup iface_zwp_primary_selection_offer_v1 */
static inline void *
zwp_primary_selection_offer_v1_get_user_data(struct zwp_primary_selection_offer_v1 *zwp_primary_selection_offer_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwp_primary_selection_offer_v1);
}

static inline uint32_t
zwp_primary_selection_offer_v1_get_version(struct zwp_primary_selection_offer_v1 *zwp_primary_selection_offer_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zwp_primary_selection_offer_v1);
}

/**
 * @ingroup iface_zwp_primary_selection_offer_v1
 *
 * To transfer the contents of the primary selection clipboard, the client
 * issues this request and indicates the mime type that it wants to
 * receive. The transfer happens through the passed file descriptor
 * (typically created with the pipe system call). The source client writes
 * the data in the mime type representation requested and then closes the
 * file descriptor.
 *
 * The receiving client reads from the read end of the pipe until EOF and
 * closes its end, at which point the transfer is complete.
 */
static inline void
zwp_primary_selection_offer_v1_receive(struct zwp_primary_selection_offer_v1 *zwp_primary_selection_offer_v1, const char *mime_type, int32_t fd)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_primary_selection_offer_v1,
			 ZWP_PRIMARY_SELECTION_OFFER_V1_RECEIVE, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_primary_selection_offer_v1), 0, mime_type, fd);
}

/**
 * @ingroup iface_zwp_primary_selection_offer_v1
 *
 * Destroy the primary selection offer.
 */
static inline void
zwp_primary_selection_offer_v1_destroy(struct zwp_primary_selection_offer_v1 *zwp_primary_selection_offer_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_primary_selection_offer_v1,
			 ZWP_PRIMARY_SELECTION_OFFER_V1_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_primary_selection_offer_v1), WL_MARSHAL_FLAG_DESTROY);
}

/**
 * @ingroup iface_zwp_primary_selection_source_v1
 * @struct zwp_primary_selection_source_v1_listener
 */
struct zwp_primary_selection_source_v1_listener {
	/**
	 * send the primary selection contents
	 *
	 * Request for the current primary selection contents from the
	 * client. Send the specified mime type over the passed file
	 * descriptor, then close it.
	 */
	void (*send)(void *data,
		     struct zwp_primary_selection_source_v1 *zwp_primary_selection_source_v1,
		     const char *mime_type,
		     int32_t fd);
	/**
	 * request for primary selection contents was canceled
	 *
	 * This primary selection source is no longer valid. The client
	 * should clean up and destroy this primary selection source.
	 */
	void (*cancelled)(void *data,
			  struct zwp_primary_selection_source_v1 *zwp_primary_selection_source_v1);
};

/**
 * @ingroup iface_zwp_primary_selection_source_v1
 */
static inline int
zwp_primary_selection_source_v1_add_listener(struct zwp_primary_selection_source_v1 *zwp_primary_selection_source_v1,
					     const struct zwp_primary_selection_source_v1_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) zwp_primary_selection_source_v1,
				     (void (**)(void)) listener, data);
}

#define ZWP_PRIMARY_SELECTION_SOURCE_V1_OFFER 0
#define ZWP_PRIMARY_SELECTION_SOURCE_V1_DESTROY 1

/**
 * @ingroup iface_zwp_primary_selection_source_v1
 */
#define ZWP_PRIMARY_SELECTION_SOURCE_V1_SEND_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_primary_selection_source_v1
 */
#define ZWP_PRIMARY_SELECTION_SOURCE_V1_CANCELLED_SINCE_VERSION 1

/**
 * @ingroup iface_zwp_primary_selection_source_v1
 */
#define ZWP_PRIMARY_SELECTION_SOURCE_V1_OFFER_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_primary_selection_source_v1
 */
#define ZWP_PRIMARY_SELECTION_SOURCE_V1_DESTROY_SINCE_VERSION 1

/** @ingroup iface_zwp_primary_selection_source_v1 */
static inline void
zwp_primary_selection_source_v1_set_user_data(struct zwp_primary_selection_source_v1 *zwp_primary_selection_source_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwp_primary_selection_source_v1, user_data);
}

/** @ingroup iface_zwp_primary_selection_source_v1 */
static inline void *
zwp_primary_selection_source_v1_get_user_data(struct zwp_primary_selection_source_v1 *zwp_primary_selection_source_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwp_primary_selection_source_v1);
}

static inline uint32_t
zwp_primary_selection_source_v1_get_version(struct zwp_primary_selection_source_v1 *zwp_primary_selection_source_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zwp_primary_selection_source_v1);
}

/**
 * @ingroup iface_zwp_primary_selection_source_v1
 *
 * This request adds a mime type to the set of mime types advertised to
 * targets. Can be called several times to offer multiple types.
 */
static inline void
zwp_primary_selection_source_v1_offer(struct zwp_primary_selection_source_v1 *zwp_primary_selection_source_v1, const char *mime_type)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_primary_selection_source_v1,
			 ZWP_PRIMARY_SELECTION_SOURCE_V1_OFFER, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_primary_selection_source_v1), 0, mime_type);
}

/**
 * @ingroup iface_zwp_primary_selection_source_v1
 *
 * Destroy the primary selection source.
 */
static inline void
zwp_primary_selection_source_v1_destroy(struct zwp_primary_selection_source_v1 *zwp_primary_selection_source_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_primary_selection_source_v1,
			 ZWP_PRIMARY_SELECTION_SOURCE_V1_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_primary_selection_source_v1), WL_MARSHAL_FLAG_DESTROY);
}

#ifdef  __cplusplus
}
#endif

#endif
