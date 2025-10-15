// 产品接口——交通方式
class Transport {
public:
    virtual void planRoute(const Location& start, const Location& end) = 0;
    virtual ~Transport() = default;
};

// 具体交通方式实现
class WalkTransport : public Transport {
    void planRoute(const Location& start, const Location& end) override {
        // 步行路径规划
    }
};
class BusTransport : public Transport {
    void planRoute(const Location& start, const Location& end) override {
        // 公交路径规划
    }
};

// 抽象工厂——交通
class TransportFactory {
public:
    virtual std::unique_ptr<Transport> createTransport() = 0;
    virtual ~TransportFactory() = default;
};
// 具体工厂
class WalkFactory : public TransportFactory {
public:
    std::unique_ptr<Transport> createTransport() override {
        return std::make_unique<WalkTransport>();
    }
};
class BusFactory : public TransportFactory {
public:
    std::unique_ptr<Transport> createTransport() override {
        return std::make_unique<BusTransport>();
    }
};

// 产品接口——优先策略
class PriorityStrategy {
public:
    virtual double calculateCost(const Route& route) = 0;
    virtual ~PriorityStrategy() = default;
};

// 具体策略
class TimePriority : public PriorityStrategy {
public:
    double calculateCost(const Route& route) override {
        // 根据时间评估
        return route.totalTime();
    }
};
class DistancePriority : public PriorityStrategy {
public:
    double calculateCost(const Route& route) override {
        // 根据距离评估
        return route.totalDistance();
    }
};

// 抽象工厂——优先策略
class PriorityFactory {
public:
    virtual std::unique_ptr<PriorityStrategy> createPriority() = 0;
    virtual ~PriorityFactory() = default;
};

// 具体策略工厂
class TimePriorityFactory : public PriorityFactory {
public:
    std::unique_ptr<PriorityStrategy> createPriority() override {
        return std::make_unique<TimePriority>();
    }
};
class DistancePriorityFactory : public PriorityFactory {
public:
    std::unique_ptr<PriorityStrategy> createPriority() override {
        return std::make_unique<DistancePriority>();
    }
};

// 客户端用法
int main() {
    // 根据用户选择创建工厂
    std::unique_ptr<TransportFactory> transportFactory = std::make_unique<BusFactory>();
    std::unique_ptr<PriorityFactory> priorityFactory = std::make_unique<TimePriorityFactory>();
    // 创建产品
    auto transport = transportFactory->createTransport();
    auto priority = priorityFactory->createPriority();
    // 调用统一接口进行路线规划与比较
    transport->planRoute(start, end);
    double cost = priority->calculateCost(route);
}
