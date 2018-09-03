# 3D-object-registration
The implementation of our method used here is described as follows: objects in the scene
are detected and recognized using the Mobilenet-Single Shot multibox Detector (SSD)
convolutional neural network using the color image frame to obtain the bounding boxes
around the required object, the corresponding point cloud is cropped according to the
detection in the previous step, the point cloud is filtered to remove outliers to make the
registration process more susceptible to convergence, two different point clouds from
different angles are registered using the ICP algorithm.

For more details, check out the report.
