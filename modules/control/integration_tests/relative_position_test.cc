/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <memory>
#include <string>
#include <utility>

#include "gmock/gmock.h"
#include "google/protobuf/text_format.h"
#include "gtest/gtest.h"
#include "modules/common/log.h"

#include "modules/common/time/time.h"
#include "modules/common/util/util.h"
#include "modules/control/common/control_gflags.h"
#include "modules/control/integration_tests/control_test_base.h"

using apollo::common::time::Clock;

namespace apollo {
namespace control {

class RelativePositionTest : public ControlTestBase {
 public:
  virtual void SetUp() {
    FLAGS_test_data_dir = "modules/control/testdata/relative_position_test/";
    FLAGS_control_conf_file =
        "modules/control/testdata/conf/lincoln_lite.pb.txt";

    FLAGS_use_relative_position = true;
    FLAGS_query_relative_time = 1.0;
  }
};

TEST_F(RelativePositionTest, simple_left) {
  FLAGS_enable_csv_debug = true;
  FLAGS_test_localization_file = "0_apollo_localization_pose.pb.txt";
  FLAGS_test_pad_file = "0_pad.pb.txt";
  FLAGS_test_planning_file = "0_apollo_planning.pb.txt";
  FLAGS_test_chassis_file = "0_apollo_canbus_chassis.pb.txt";
  ControlTestBase::SetUp();
  RUN_GOLDEN_TEST;
}

}  // namespace control
}  // namespace apollo
