//
// Created by JOSS0001 on 2026-01-07.
//

#ifndef PLATFORM_H
#define PLATFORM_H

#include <string>

using namespace  std;

class StreamingService {
public:
    virtual string getServiceName() = 0;
    virtual void playContent(string title) = 0;
    virtual double monthlyCost() = 0;
};

class BaseStreamingService : public StreamingService{
protected:
    string serviceName;
    double cost;
public:
    virtual ~BaseStreamingService() = default;
    BaseStreamingService(string name, double cost);

    string getServiceName() override;
    double monthlyCost() override;
    //void playContent(string title) override;
};

class Netflix : public BaseStreamingService {
public:
    Netflix(string Name, double cost);
    void playContent(string title) override;
};

class Spotify : public BaseStreamingService {
public:
    Spotify(string Name, double cost);
    void playContent(string title) override;
};

class Disney : public BaseStreamingService {
public:
    Disney(string Name, double cost);
    void playContent(string title) override;
};


#endif //PLATFORM_H
