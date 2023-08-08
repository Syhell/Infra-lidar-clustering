#include "infra_lidar_clustering/infra_lidar_clustering_node.h"

namespace infra_lidar_clustering_node
{
    using PclPointXYZ = pcl::PointCloud<pcl::PointXYZ>
    InfraLidarClusteringNode::LidaClusteringNode() : nh()
    {
        //read parametor from launch file
        nh.param("lidar_clustering/clip_min_width", clip_min_width, -0.5);
        nh.param("lidar_clustering/clip_max_width", clip_max_witdh, 0.5);
        nh.param("lidar_clustering/clip_min_distance", clip_min_distance, 0.2);
        nh.param("lidar_clustering/clip_max_distance", clip_max_distance, 3.0);
        nh.param("lidar_clustering/clip_min_height", clip_min_height, -0.85);
        nh.param("lidar_clustering/clip_max_height", clip_max_height, 0.5);
        
        //subscliber by using message_filters
        pose_sub.subsclibe(nh, "/infra_current_pose", 1);
        clippedCloud_sub.subsclibe(nh, "/points_no_ground", 1);
        Sync(SyPl(10), pose_sub, clippedCloud_sub);
        Sync.registerCallback(boost::bind(&sync_callback, _1, _2));
    }

    void InfraLidarClusteringNode::sync_callback(const geometry_msgs::PoseStamped::ConstPtr& in_pose_msg,const sensor_msgs::PointCloud2ConstPtr& in_cloud_msg)
    {
        PclPointXYZ::Ptr current_in_points_ptr(new PclPointXYZ);
        pcl::fromROSMsg(*in_cloud_msg, *current_in_points);
        heder_ = in_cloud_msg->header;

        PclPointXYZ::Ptr clipped_cloud(new PclPointXYZ);
        geometry_msgs::PoseStamped
        ClippedCloud(current_in_points_ptr, )

    }

}