#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/crop_box.h>
#include <pcl/visualization/pcl_visualizer.h>

int
 main (int argc, char** argv)
{
  pcl::visualization::PCLVisualizer viewer("Cloud Viewer");
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered2 (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered3 (new pcl::PointCloud<pcl::PointXYZ>);
  if (pcl::io::loadPCDFile<pcl::PointXYZ> ("/home/shah/ros_catkin_ws/human2.pcd", *cloud) == -1) //* load the file
  {
    PCL_ERROR ("Couldn't read file pcd \n");
    return (-1);
  }

  // Create the filtering object
  pcl::PassThrough<pcl::PointXYZ> pass;
  pass.setInputCloud (cloud);
  pass.setFilterFieldName ("z");
  pass.setFilterLimits (2.1, 2.5);
  // pass.setFilterLimitsNegative (true);
  pass.filter (*cloud_filtered);

  pcl::PassThrough<pcl::PointXYZ> pass2;
  pass2.setInputCloud (cloud_filtered);
  pass2.setFilterFieldName ("y");
  pass2.setFilterLimits (0.3, 5);
  // pass.setFilterLimitsNegative (true);
  pass2.filter (*cloud_filtered2);

  /*pcl::PassThrough<pcl::PointXYZ> pass3;
  pass3.setInputCloud (cloud_filtered);
  pass3.setFilterFieldName ("x");
  pass3.setFilterLimits (-0.1, 3);
  // pass.setFilterLimitsNegative (true);
  pass3.filter (*cloud_filtered3);*/

  /*pcl::CropBox<pcl::PointXYZ> boxFilter;
  boxFilter.setMin(Eigen::Vector4f(0.76, 0.3922, 2.56, 1.0));
  boxFilter.setMax(Eigen::Vector4f(1, 1, 3.9, 1.0));
  boxFilter.setInputCloud(cloud);
  boxFilter.filter(*cloud_filtered);*/

  pcl::io::savePCDFileASCII ("human2z.pcd", *cloud_filtered2);
  
  viewer.addPointCloud(cloud_filtered2,"cloud");
  viewer.spin();
  
  

  return (0);
}
