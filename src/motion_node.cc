#include <sara_shield_utils/motion_node.h>

#include <ros/ros.h>

namespace sara_shield_utils {

MotionNode::MotionNode():
  nh{},
  target_joint_pos_publisher_(nh.advertise<std_msgs::Float32MultiArray>("/sara_shield/goal_joint_pos", 100)),
  robot_current_pos_sub_(nh.subscribe("/sara_shield/current_joint_pos", 100, &MotionNode::observeRobotJointCallback, this)),
  timer_(nh.createTimer(ros::Duration(0.05), &MotionNode::main_loop, this))
{
  joint_positions_.push_back(std::vector<float>{0.02843269519507885, 1.206194281578064, -0.023943336680531502, 2.459402322769165, -0.055654916912317276, 1.2741211652755737});
  //joint_positions_.push_back(std::vector<float>{0.04870995506644249, 0.5328424572944641, -0.024140985682606697, 1.8567579984664917, -0.05666724219918251, 1.3085459470748901});
  //joint_positions_.push_back(std::vector<float>{0.09027132391929626, -0.28132978081703186, -0.09771814942359924, 1.2479532957077026, -0.0566195584833622, 1.5703829526901245});
  joint_positions_.push_back(std::vector<float>{0.0663507878780365, -1.2192331552505493, -0.07407346367835999, 0.3012414872646332, 0.055481042712926865, 1.570431113243103});
  //joint_positions_.push_back(std::vector<float>{0.09027132391929626, -0.28132978081703186, -0.09771814942359924, 1.2479532957077026, -0.0566195584833622, 1.5703829526901245});
  //joint_positions_.push_back(std::vector<float>{0.04870995506644249, 0.5328424572944641, -0.024140985682606697, 1.8567579984664917, -0.05666724219918251, 1.3085459470748901});
  joint_positions_.push_back(std::vector<float>{0.02843269519507885, 1.206194281578064, -0.023943336680531502, 2.459402322769165, -0.055654916912317276, 1.2741211652755737});  
  // pick and place
  /* joint_positions_.push_back(std::vector<float>{1.5644749402999878, -1.1748076677322388, 0.22716817259788513, 0.7250214219093323, -0.15373364090919495, -1.2623881101608276});
  joint_positions_.push_back(std::vector<float>{1.1536554098129272, -0.48822537064552307, 0.2271321713924408, 0.7376947999000549, -0.15369167923927307, -1.3029247522354126});
  joint_positions_.push_back(std::vector<float>{-1.2421709299087524, -0.2761944830417633, 0.2675369679927826, 0.9213951230049133, -0.11488667130470276, -1.5452157258987427});
  joint_positions_.push_back(std::vector<float>{-1.2462514638900757, -1.084224820137024, 0.1774815022945404, 0.9335830807685852, -0.11552181839942932, -0.9712492823600769});
  joint_positions_.push_back(std::vector<float>{-1.2421709299087524, -0.2761944830417633, 0.2675369679927826, 0.9213951230049133, -0.11488667130470276, -1.5452157258987427});
  joint_positions_.push_back(std::vector<float>{1.1536554098129272, -0.48822537064552307, 0.2271321713924408, 0.7376947999000549, -0.15369167923927307, -1.3029247522354126});
  joint_positions_.push_back(std::vector<float>{1.5644749402999878, -1.1748076677322388, 0.22716817259788513, 0.7250214219093323, -0.15373364090919495, -1.2623881101608276});
  */
}
  //joint_positions_.push_back(std::vector<float>{1.7, -1.40, 0.0, 0.0, 0,0, 0.0});
  //joint_positions_.push_back(std::vector<float>{-1.7, -0.60, 0.0, 0.0, 0,0, 0.0});
  //joint_positions_.push_back(std::vector<float>{1.7, -1.40, 0.0, 0.0, 0,0, 0.0});}

void MotionNode::main_loop(const ros::TimerEvent &) {
  if(init_)
  {
    std_msgs::Float32MultiArray goal_joint_position;
    goal_joint_position.data = joint_positions_[this_motion_];
    target_joint_pos_publisher_.publish(goal_joint_position);
  }
}

void MotionNode::observeRobotJointCallback(const std_msgs::Float32MultiArray& msg) {
  if(!init_){  
    init_ = true;
  }
  std::vector<float> joint_position_vec(msg.data.begin(), msg.data.end());
  for (int i = 0; i < joint_position_vec.size(); i++) {
    if (std::abs(joint_position_vec[i] - joint_positions_[this_motion_][i]) > accuracy_) {
      return;
    }
  }
  // increase motion
  if (this_motion_ == joint_positions_.size() - 1) {
    this_motion_ = 0;
  } else {
    this_motion_++;
  }
}

}
