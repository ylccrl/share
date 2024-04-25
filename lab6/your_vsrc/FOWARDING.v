module FOWARDING (
    input       [ 0 : 0]        rf_we_mem,
    input       [ 0 : 0]        rf_we_wb,
    input       [ 4 : 0]        rf_wa_mem,
    input       [ 4 : 0]        rf_wa_wb,
    input       [31 : 0]        rf_wd_mem,
    input       [31 : 0]        rf_wd_wb,
    input       [ 4 : 0]        rf_ra0_ex,
    input       [ 4 : 0]        rf_ra1_ex,

    output      [ 0 : 0]        rf_rd0_fe,
    output      [ 0 : 0]        rf_rd1_fe,
    output      [31 : 0]        rf_rd0_fd,
    output      [31 : 0]        rf_rd1_fd
);

wire [ 0 : 0] mem_we,rf_rd0_fe_mem,rf_rd1_fe_mem,wb_we,rf_rd0_fe_wb,rf_rd1_fe_wb;
//MEM阶段前递使能
assign mem_we = rf_we_mem&&(rf_wa_mem!=5'b0);
assign rf_rd0_fe_mem = mem_we&&(rf_ra0_ex==rf_wa_mem);
assign rf_rd1_fe_mem = mem_we&&(rf_ra1_ex==rf_wa_mem);
//WB阶段前递使能
assign wb_we = rf_we_wb&&(rf_wa_wb!=5'b0);
assign rf_rd0_fe_wb = wb_we&&(rf_ra0_ex==rf_wa_wb);
assign rf_rd1_fe_wb = wb_we&&(rf_ra1_ex==rf_wa_wb);

assign rf_rd0_fe = rf_rd0_fe_mem||rf_rd0_fe_wb;
assign rf_rd1_fe = rf_rd1_fe_mem||rf_rd1_fe_wb;

assign rf_rd0_fd = rf_rd0_fe_mem?rf_wd_mem:(rf_rd0_fe_wb?rf_wd_wb:32'b0);
assign rf_rd1_fd = rf_rd1_fe_mem?rf_wd_mem:(rf_rd1_fe_wb?rf_wd_wb:32'b0);

endmodule