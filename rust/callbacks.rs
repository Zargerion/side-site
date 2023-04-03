fn main() {

    let var_on_on_successed = || println("Nice!");
    let var_on_on_failed = on_failed();

    external::handler(var_on_on_successed, var_on_on_failed);
}

fn on_successed() {
    println("Nice!");
}

fn on_failed() {
    println("Not nice!");
}

mod external {
    pub fn handler(on_successed: fn(), on_failed: fn()) {
        let ret = do_http_call();
        match ret {
            true  => on_successed();
            false => on_failed();
        }
    }

    fn do_http_call() -> bool {
        false
    }
}