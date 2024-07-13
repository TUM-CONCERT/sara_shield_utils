# Sara Shield Utils
Collection of rosnodes for debugging and testing different parts of [sara-shield](https://github.com/TUM-CONCERT/sara-shield-xbot2). 

## Dependencies:
- CONCERT: None
- Other: None


## Installation
Install this project just like any other ros packages
1. Clone it into `catkin_ws/src` using `https://github.com/TUM-CONCERT/sara_shield_utils.git`
2. Build the environment using `catkin build`
3. Source the environment using `source devel/setup.bash`

## Usage
At the moment, this repository contains two rosnodes that are useful for testing.

The first is called `drive_to_position` and sends out a rosmessage to drive the robot to a specified  and hardcoded location by sending out a meesage ONCE.

The second rosnode is called `motion_node` and lets the robot follow pre-defined trajectories in the following way: A certain number of hard-coded waypoints form a trajectory. At start, the first trajectory is send as ros message. As soon as it is observed that the joint angles match the ones of the waypoint, the next waypoint is sent. The trajectory is cyclically repeated. Therefore, the trajectory should idealy end at the start position to ensure smooth trajectory loops.
3 trajectories that were used for real-robot tests are already defined: `PICK_AND_PLACE`, `DRILL` and `SIMPLE_MOVE`.

To run, use rosrun:
```
rosrun sara_shield_utils drive_to_position
```
or
```
rosrun sara_shield_utils motion_node
```