class A{
    private:
        static std::shared_ptr<A> instance;
        A();
    public:
        static std::shared_ptr<A> creatInstance();
};

std::shared_ptr<A> A::creatInstance(){
    if(!instance){
        instance=std::make_shared<A>();
    }
    return instance;
}


