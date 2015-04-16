/*
 * Copyright 2015 Aldebaran
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef INFO_CONVERTER_HPP
#define INFO_CONVERTER_HPP

/**
* LOCAL includes
*/
#include "converter_base.hpp"
#include <alrosbridge/message_actions.h>

/**
* ROS includes
*/
#include <std_msgs/String.h>


namespace alros
{
namespace converter
{

class InfoConverter : public BaseConverter<InfoConverter>
{

  typedef boost::function<void(std_msgs::String)> Callback_t;

public:
  InfoConverter( const std::string& name, float frequency, const qi::SessionPtr& sessions );

  void reset();

  void registerCallback( const message_actions::MessageAction action, Callback_t cb );

  void callAll( const std::vector<message_actions::MessageAction>& actions );

private:
  /** Memory (Proxy) configurations */
  qi::AnyObject p_memory_;

  /** The keys to get from ALMemory */
  std::vector<std::string> keys_;
  std::map<message_actions::MessageAction, Callback_t> callbacks_;

  std_msgs::String msg_;
};

} //converter
} //alros

#endif
