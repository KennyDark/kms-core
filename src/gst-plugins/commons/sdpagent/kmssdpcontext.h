/*
 * (C) Copyright 2015 Kurento (http://kurento.org/)
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */
#ifndef _KMS_SDP_CONTEXT_H_
#define _KMS_SDP_CONTEXT_H_

#include <gst/sdp/gstsdpmessage.h>

typedef enum  {
  IPV4,
  IPV6
} SdpIPv;

typedef struct _SdpMediaGroup SdpMediaGroup;
typedef struct _SdpMediaConfig SdpMediaConfig;
typedef struct _SdpMessageContext SdpMessageContext;

SdpMessageContext *kms_sdp_message_context_new (SdpIPv ipv, GError **error);
gboolean kms_sdp_message_context_set_common_session_attributes (SdpMessageContext *ctx, const GstSDPMessage *msg, GError **error);
void kms_sdp_message_context_destroy (SdpMessageContext *ctx);
SdpMediaConfig * kms_sdp_message_context_add_media (SdpMessageContext *ctx, GstSDPMedia *media);
gint kms_sdp_media_config_get_id (SdpMediaConfig * mconf);
gboolean kms_sdp_media_config_is_rtcp_mux (SdpMediaConfig * mconf);
SdpMediaGroup * kms_sdp_media_config_get_group (SdpMediaConfig * mconf);
GstSDPMedia * kms_sdp_media_config_get_sdp_media (SdpMediaConfig * mconf);
GstSDPMessage * kms_sdp_message_context_pack (SdpMessageContext *ctx, GError **error);
SdpMediaGroup * kms_sdp_message_context_create_group (SdpMessageContext *ctx, guint gid);
gint kms_sdp_media_group_get_id (SdpMediaGroup *group);
SdpMediaGroup * kms_sdp_message_context_get_group (SdpMessageContext *ctx, guint gid);
gboolean kms_sdp_message_context_add_media_to_group (SdpMediaGroup *group, SdpMediaConfig *media, GError **error);
gboolean kms_sdp_message_context_parse_groups_from_offer (SdpMessageContext *ctx, const GstSDPMessage *offer, GError **error);

#endif /* _KMS_SDP_CONTEXT_ */