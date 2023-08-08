#ifdef INFR_LIDAR_CLUSTERING_NODE_H
#define INFR_LIDAR_CLUSTERING_NODE_H

#include "infra_lidar_clustering/infra_lidar_clustering.h"
#include <ros/ros.h>
#include <visualization_msgs/MarkerArray.h>
#include <visualization_msgs/Marker.h>

#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <geometry_msgs/PoseStamped.h>
#include <sensor_msgs/PointCloud2.h>

#include "itolab_senior_car_msgs/Centroids.h"
#include "itolab_senior_car_msgs/CloudClusterArray.h"
#include "itolab_senior_car_msgs/DetectedObjectArray.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

namespace infra_lidar_clustering_node
{
    class InfraLidarClusteringNode
    {
        public:
            LidarClusteringNode();
            void sync_callback(const geometry_msgs::PoseStamped::ConstPtr& in_pose_msg,
                               const sensor_msgs::PointCloud2ConstPtr& in_cloud_msg);
            void clustering(const pcl::PointCloud<pcl::PointXYZ>::Ptr in_ptr, 
                            std::vector<lidar_clustering::ClusterPtr>& clusters,
                            itolab_senior_car_msgs::Centroids& centroids,
                            float max_cluster_distance); 
        private:
            ros::NodeHandle nh;
            
            ros::Publisher cluster_cloud_pub;
            
            message_filters::Subscriber<geometry_msgs::PoseStamped> pose_sub;
            message_filters::Subscriber<sensor_msgs::PointCloud2> clippedCloud_sub;
            typedef message_filters::sync_policies::ApproximateTime<geometry_msgs::PoseStamped, sensor_msgs::PointCloud2> SyPl;
            message_filters::Synchronizer<SyPl> Sync;

            double clip_min_height = -0.85;
            double clip_max_height = 0.5;
            std::string sub_topic = "cliped_cloud";
        
        

    }
}




#endif //INFR_LIDAR_CLUSTERING_NODE_H