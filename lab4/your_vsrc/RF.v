`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/04/09 20:51:29
// Design Name: 
// Module Name: RF
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module RF (
    input                   [ 0 : 0]        clk,

    input                   [ 4 : 0]        rf_ra_k,
    input                   [ 4 : 0]        rf_ra_j,   
    input                   [ 4 : 0]        rf_ra_d,

    input                   [ 0 : 0]        rf_we,
    input                   [31 : 0]        rf_wd,

    output                  [31 : 0]        rf_rd_k,
    output                  [31 : 0]        rf_rd_j,
    output                  [31 : 0]        rf_rd_d,

    input                   [ 4 : 0]        dbg_reg_ra,
    output                  [31 : 0]        dbg_reg_rd
);

    reg [31 : 0] reg_file [0 : 31];
    wire [4:0] rf_wa = rf_ra_d;
    // 用于初始化寄存器
    integer i;
    initial begin
        for (i = 0; i < 32; i = i + 1)
            reg_file[i] = 0;
    end

    always @(posedge clk) begin
        if (rf_we) begin
            reg_file[rf_wa] <= (rf_wa==0)?0:rf_wd;
        end
    end
    
    assign rf_rd_k = reg_file[rf_ra_k];
    assign rf_rd_j = reg_file[rf_ra_j];
    assign rf_rd_d = reg_file[rf_ra_d];

    assign dbg_reg_rd = reg_file[dbg_reg_ra];
endmodule
