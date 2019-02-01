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

#pragma once

#include <string>

#include <common/uri/url.h>

#include "server/commands_info/stream/stream_info.h"

namespace iptv_cloud {
namespace server {
namespace stream {

class GetLogInfo : public StreamInfo {
 public:
  typedef StreamInfo base_class;
  typedef common::uri::Url url_t;

  GetLogInfo();
  explicit GetLogInfo(stream_id_t stream_id, const std::string& feedback_dir, const url_t& log_path);

  url_t GetLogPath() const;
  std::string GetFeedbackDir() const;

 protected:
  common::Error DoDeSerialize(json_object* serialized) override;
  common::Error SerializeFields(json_object* out) const override;

 private:
  std::string feedback_dir_;
  common::uri::Url path_;
};

}  // namespace stream
}  // namespace server
}  // namespace iptv_cloud
