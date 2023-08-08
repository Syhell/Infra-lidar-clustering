#include "infra_lidar_clustering/infra_lidar_clustering_node.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "infra_lidar_clustering");
    infra_lidar_clustering_node::InfraLidarClusteringNode node;
    ros::spin();
}