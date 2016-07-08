#ifndef __CONNECTION__PROCESSOR__H__
#define __CONNECTION__PROCESSOR__H__

#include <memory>

namespace honoka
{
    class Reactor;
    class Connection;

    class Connection_processor
    {
    public:

        
        Connection_processor(Reactor* reactor);
	void handle(std::shared_ptr<Connection> conn);

    private:
        void passive_conn(std::shared_ptr<Connection> conn);
        void active_conn(std::shared_ptr<Connection> conn);
        void read(std::shared_ptr<Connection> conn);
        void write(std::shared_ptr<Connection> conn);
        void passive_close(std::shared_ptr<Connection> conn);
        void active_close(std::shared_ptr<Connection> conn);
        void timeout(std::shared_ptr<Connection> conn);

        Reactor* reactor_;
    };
}

//抽象connection的处理为一个，将上下文（只有buffer？）传进去，这里的connection包含了conection的处理，将其抽象出来设为单例
//让客户继承编写自己的connection处理和connection_context
//甚至可以继承了以后使用python等脚本语言

#endif
