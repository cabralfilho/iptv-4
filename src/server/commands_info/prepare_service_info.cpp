/*  Copyright (C) 2014-2018 FastoGT. All right reserved.
    This file is part of iptv_cloud.
    iptv_cloud is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    iptv_cloud is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with iptv_cloud.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "server/commands_info/prepare_service_info.h"

#include <string>

namespace iptv_cloud {
namespace server {

PrepareServiceInfo::PrepareServiceInfo()
    : base_class(),
      feedback_directory_(),
      timeshifts_directory_(),
      hls_directory_(),
      playlists_directory_(),
      dvb_directory_(),
      capture_card_directory_() {}

std::string PrepareServiceInfo::GetFeedbackDirectory() const {
  return feedback_directory_;
}

std::string PrepareServiceInfo::GetTimeshiftsDirectory() const {
  return timeshifts_directory_;
}

std::string PrepareServiceInfo::GetHlsDirectory() const {
  return hls_directory_;
}

std::string PrepareServiceInfo::GetPlaylistsDirectory() const {
  return playlists_directory_;
}

std::string PrepareServiceInfo::GetDvbDirectory() const {
  return dvb_directory_;
}

std::string PrepareServiceInfo::GetCaptureDirectory() const {
  return capture_card_directory_;
}

common::Error PrepareServiceInfo::SerializeFields(json_object* out) const {
  json_object_object_add(out, PREPARE_SERVICE_INFO_FEEDBACK_DIRECTORY_FIELD,
                         json_object_new_string(feedback_directory_.c_str()));
  json_object_object_add(out, PREPARE_SERVICE_INFO_TIMESHIFTS_DIRECTORY_FIELD,
                         json_object_new_string(timeshifts_directory_.c_str()));
  json_object_object_add(out, PREPARE_SERVICE_INFO_HLS_DIRECTORY_FIELD, json_object_new_string(hls_directory_.c_str()));
  json_object_object_add(out, PREPARE_SERVICE_INFO_PLAYLIST_DIRECTORY_FIELD,
                         json_object_new_string(playlists_directory_.c_str()));
  json_object_object_add(out, PREPARE_SERVICE_INFO_DVB_DIRECTORY_FIELD, json_object_new_string(dvb_directory_.c_str()));
  json_object_object_add(out, PREPARE_SERVICE_INFO_CAPTURE_CARD_DIRECTORY_FIELD,
                         json_object_new_string(capture_card_directory_.c_str()));
  return common::Error();
}

common::Error PrepareServiceInfo::DoDeSerialize(json_object* serialized) {
  PrepareServiceInfo inf;
  json_object* jfeedback_directory = nullptr;
  json_bool jfeedback_directory_exists =
      json_object_object_get_ex(serialized, PREPARE_SERVICE_INFO_FEEDBACK_DIRECTORY_FIELD, &jfeedback_directory);
  if (jfeedback_directory_exists) {
    inf.feedback_directory_ = json_object_get_string(jfeedback_directory);
  }

  json_object* jtimeshifts_directory = nullptr;
  json_bool jtimeshifts_directory_exists =
      json_object_object_get_ex(serialized, PREPARE_SERVICE_INFO_TIMESHIFTS_DIRECTORY_FIELD, &jtimeshifts_directory);
  if (jtimeshifts_directory_exists) {
    inf.timeshifts_directory_ = json_object_get_string(jtimeshifts_directory);
  }

  json_object* jhls_directory = nullptr;
  json_bool jhls_directory_exists =
      json_object_object_get_ex(serialized, PREPARE_SERVICE_INFO_HLS_DIRECTORY_FIELD, &jhls_directory);
  if (jhls_directory_exists) {
    inf.hls_directory_ = json_object_get_string(jhls_directory);
  }

  json_object* jplaylists_directory = nullptr;
  json_bool jplaylists_directory_exists =
      json_object_object_get_ex(serialized, PREPARE_SERVICE_INFO_PLAYLIST_DIRECTORY_FIELD, &jplaylists_directory);
  if (jplaylists_directory_exists) {
    inf.playlists_directory_ = json_object_get_string(jplaylists_directory);
  }

  json_object* jdvb_directory = nullptr;
  json_bool jdvb_directory_exists =
      json_object_object_get_ex(serialized, PREPARE_SERVICE_INFO_DVB_DIRECTORY_FIELD, &jdvb_directory);
  if (jdvb_directory_exists) {
    inf.dvb_directory_ = json_object_get_string(jdvb_directory);
  }

  json_object* jcapture_card_directory = nullptr;
  json_bool jcapture_card_directory_exists = json_object_object_get_ex(
      serialized, PREPARE_SERVICE_INFO_CAPTURE_CARD_DIRECTORY_FIELD, &jcapture_card_directory);
  if (jcapture_card_directory_exists) {
    inf.capture_card_directory_ = json_object_get_string(jcapture_card_directory);
  }

  *this = inf;
  return common::Error();
}

}  // namespace server
}  // namespace iptv_cloud