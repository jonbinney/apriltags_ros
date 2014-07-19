#include <apriltags_ros/apriltag_detector.h>
#include <ros/ros.h>

int main(int argc, char **argv){
  ros::init(argc, argv, "apriltag_detector");
  ros::NodeHandle nh;
  ros::NodeHandle pnh("~");

  apriltags_ros::AprilTagDetector detector(nh, pnh);

  // Check whether to run multiple detection threads
  int num_threads;
  pnh.param("num_threads", num_threads, 1);
  if(num_threads > 1){
    ROS_INFO("Starting multi-threaded spinner with %d threads", num_threads);
    ros::AsyncSpinner spinner(num_threads);
    spinner.start();
    ros::waitForShutdown();
  }
  else{
    ros::spin();
  }
}
