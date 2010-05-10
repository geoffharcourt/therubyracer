#include "v8_cxt.h"
#include "v8_str.h"
#include "v8_obj.h"
#include "v8_msg.h"
#include "v8_func.h"
#include "v8_script.h"
#include "v8_template.h"
#include "v8_standalone.h"
#include "converters.h"

#include <stdio.h>

extern "C" {
    /**
     * ruby init method for the extension
     */
    void Init_v8();
}

VALUE rb_mModule;
VALUE rb_cV8;

extern "C" {
    void Init_v8() {
        
        rb_mModule = rb_define_module("V8");
        rb_define_singleton_method(rb_mModule, "what_is_this?", (VALUE(*)(...)) v8_what_is_this, 1);
        
        V8_To = rb_define_module_under(rb_mModule, "To");
                
        //native module setup
        VALUE rb_mNative = rb_define_module_under(rb_mModule, "C");
        
        rr_init_cxt();
        rr_init_str();
        rr_init_script();
        rr_init_template();
        rr_init_obj();
        rr_init_func();
        rr_init_msg();                                
    }
}
