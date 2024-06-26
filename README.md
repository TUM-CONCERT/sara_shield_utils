# Sara Shield Utils

## Installation
Install it like any other ROS project:
1. clone the repository into your ```catkin_ws/src```
2. ```cd LOCATION/catkin_ws && catkin build && source devel/setup.bash```

## Usage
At the moment, this repository contains two rosnodes that are useful for testing.

The first is called `drive_to_position` and sends out a rosmessage to drive the robot to a specified  and hardcoded location by sending out a meesage ONCE.

The second rosnode is called `motion_node` and lets the robot follow pre-defined trajectories in the following way: A certain number of hard-coded waypoints form a trajectory. At start, the first trajectory is send as ros message. As soon as it is observed that the joint angles match the ones of the waypoint, the next waypoint is sent. The trajectory is cyclically repeated. Therefore, the trajectory should idealy end at the start position to ensure smooth trajectory loops.
3 trajectories that were used for real-robot tests are already defined: PICK_AND_PLACE, DRILL and SIMPLE_MOVE.

To run, use rosrun:
```
rosrun sara_shield_utils drive_to_position
```
or
```
rosrun sara_shield_utils motion_node
```