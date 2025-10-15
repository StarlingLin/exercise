// ��Ʒ�ӿڡ�����ͨ��ʽ
class Transport {
public:
    virtual void planRoute(const Location& start, const Location& end) = 0;
    virtual ~Transport() = default;
};

// ���彻ͨ��ʽʵ��
class WalkTransport : public Transport {
    void planRoute(const Location& start, const Location& end) override {
        // ����·���滮
    }
};
class BusTransport : public Transport {
    void planRoute(const Location& start, const Location& end) override {
        // ����·���滮
    }
};

// ���󹤳�������ͨ
class TransportFactory {
public:
    virtual std::unique_ptr<Transport> createTransport() = 0;
    virtual ~TransportFactory() = default;
};
// ���幤��
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

// ��Ʒ�ӿڡ������Ȳ���
class PriorityStrategy {
public:
    virtual double calculateCost(const Route& route) = 0;
    virtual ~PriorityStrategy() = default;
};

// �������
class TimePriority : public PriorityStrategy {
public:
    double calculateCost(const Route& route) override {
        // ����ʱ������
        return route.totalTime();
    }
};
class DistancePriority : public PriorityStrategy {
public:
    double calculateCost(const Route& route) override {
        // ���ݾ�������
        return route.totalDistance();
    }
};

// ���󹤳��������Ȳ���
class PriorityFactory {
public:
    virtual std::unique_ptr<PriorityStrategy> createPriority() = 0;
    virtual ~PriorityFactory() = default;
};

// ������Թ���
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

// �ͻ����÷�
int main() {
    // �����û�ѡ�񴴽�����
    std::unique_ptr<TransportFactory> transportFactory = std::make_unique<BusFactory>();
    std::unique_ptr<PriorityFactory> priorityFactory = std::make_unique<TimePriorityFactory>();
    // ������Ʒ
    auto transport = transportFactory->createTransport();
    auto priority = priorityFactory->createPriority();
    // ����ͳһ�ӿڽ���·�߹滮��Ƚ�
    transport->planRoute(start, end);
    double cost = priority->calculateCost(route);
}
