all:	
	g++ -o pbtrans -I ~/workspace/caffe/distribute/include/ -I /usr/local/cuda-8.0/include model-dump.cpp  -L ~/workspace/caffe/distribute/lib -lcaffe -lboost_system 
