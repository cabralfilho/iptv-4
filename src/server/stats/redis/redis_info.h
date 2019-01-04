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

#include <common/serializer/json_serializer.h>

#include "server/redis/config.h"

namespace iptv_cloud {
namespace server {
namespace stats {
namespace redis {

class RedisInfo : public common::serializer::JsonSerializer<RedisInfo> {
 public:
  typedef JsonSerializer<RedisInfo> base_class;
  typedef iptv_cloud::server::redis::redis_configuration_t redis_configuration_t;
  RedisInfo();

  redis_configuration_t GetConfig() const;

 protected:
  common::Error DoDeSerialize(json_object* serialized) override;
  common::Error SerializeFields(json_object* out) const override;

 private:
  redis_configuration_t config_;
};

}  // namespace redis
}  // namespace stats
}  // namespace server
}  // namespace iptv_cloud
