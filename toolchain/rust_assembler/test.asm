.data:
    blah = 5
    wah = "Hello world!!!"
    nah = 17
.code:
    begin:
    LOAD blah,B
    ADD A,B
    RSTORE A,B
    end:
    HALT
