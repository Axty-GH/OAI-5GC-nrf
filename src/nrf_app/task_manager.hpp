/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*! \file task_manager.hpp
 \brief
 \author
 \company Eurecom
 \date 2020
 \email: tien-thinh.nguyen@eurecom.fr
 */

#ifndef TASK_MANAGER_H_
#define TASK_MANAGER_H_

#include "nrf_event.hpp"

#include <linux/types.h>
#include <sys/timerfd.h>

using namespace oai::nrf::app;

namespace oai {
  namespace nrf {
    namespace app {

    class nrf_event;
    class task_manager {

      public:
        task_manager(nrf_event& ev);
        void manage_tasks();
        void run();

      private:
        void wait_for_cycle();
        nrf_event& event_sub_;
        int sfd;
      };
    }
  }
}

#endif
