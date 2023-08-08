#include "infra_lidar_clustering/infra_lidar_clustering_node.h"

namespace infra_lidar_clustering_node
{
    using PclPointXYZ = pcl::PointCloud<pcl::PointXYZ>
    InfraLidarClusteringNode::LidaClusteringNode() : nh()
    {
        point_cloud_sub = nh.ros::Subscriber nh.subscribe(sub_topic, 1, &InfraLidarClusteringNode::PointSub_callback, this);
            
    }

    void InfraLidarClusteringNode::PointSub_callback(const sensor_msgs::PointCloud2ConstPtr& in_msg)
    {
        PclPointXYZ::Ptr current_sub_cloud_ptr(new PclPointXYZ);
        pcl::fromROSMsg(*in_msg, *current_sub_cloud_ptr);
        PclPointXYZ::Ptr cliped_cloud_ptr(new PclPointXYZ);
        clipCloud(current_sub_cloud_ptr, cliped_cloud_ptr, )
    }
}