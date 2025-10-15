#include <iostream>
#include <memory>

class Language
{
public:
	virtual ~Language() = default;
	virtual void test() = 0;
	virtual Language* clone() const = 0;
};

class Chinese : public Language
{
public:
	void test() override 
	{
		std::cout << "中文" << std::endl;
	}
	Language* clone() const override 
	{
		return new Chinese();
	}
};

class English : public Language
{
public:
	void test() override 
	{
		std::cout << "英文" << std::endl;
	}
	Language* clone() const override 
	{
		return new English();
	}
};

class ProtoMgr
{
public:
	static ProtoMgr& getInstance()
	{
		static ProtoMgr instance;
		return instance;
	}
	Language* createLanguage() const 
	{
		return mProto ? mProto->clone() : nullptr;
	}
	void changeProto(Language* proto)
	{
		mProto.reset(proto);
	}
	
	ProtoMgr(const ProtoMgr&) = delete;
	ProtoMgr& operator=(const ProtoMgr&) = delete;

private:
	ProtoMgr() : mProto(new Chinese) {}
	std::shared_ptr<Language> mProto;
};

int main() {
	ProtoMgr& mgr = ProtoMgr::getInstance(); //默认原型为中文
	using SLang = std::shared_ptr<Language>;
	SLang lang01(mgr.createLanguage());
	lang01->test();
	SLang lang02(mgr.createLanguage());
	lang02->test();
	mgr.changeProto(new English); //变更原型为英语
	SLang lang03(mgr.createLanguage());
	lang03->test();
	SLang lang04(mgr.createLanguage());
	lang04->test();
}