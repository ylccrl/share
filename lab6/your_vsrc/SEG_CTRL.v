module SEG_CTRL (
    input       [ 0 : 0]        rf_we_ex,
    input       [ 1 : 0]        rf_wd_sel_ex,
    input       [ 4 : 0]        rf_wa_ex,
    input       [ 4 : 0]        rf_ra0_id,
    input       [ 4 : 0]        rf_ra1_id,
    input       [ 0 : 0]        npc_sel_ex,

    output      [ 0 : 0]        stall_pc,
    output      [ 0 : 0]        stall_if_id,
    output      [ 0 : 0]        flush_if_id,
    output      [ 0 : 0]        flush_id_ex
);
    
    wire [ 0: 0] we = rf_we_ex&&(rf_wa_ex!=5'b0)&&(rf_wd_sel_ex==2'b10);
    wire [ 0: 0] ce = (rf_ra0_id==rf_wa_ex)||(rf_ra1_id==rf_wa_ex);
    assign stall_pc = we&&ce;
    assign stall_if_id = stall_pc;

    assign flush_if_id = npc_sel_ex;
    assign flush_id_ex = npc_sel_ex;
endmodule