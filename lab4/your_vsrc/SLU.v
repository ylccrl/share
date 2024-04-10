`timescale 1ns / 1ps
`include "dmem_type.vh"

//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/04/09 20:26:32
// Design Name: 
// Module Name: SLU
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


module SLU (
    input                   [31 : 0]                addr,
    input                   [ 3 : 0]                dmem_access,

    input                   [31 : 0]                rd_in,
    input                   [31 : 0]                wd_in,

    output      reg         [31 : 0]                rd_out,
    output      reg         [31 : 0]                wd_out
);
    //读取指令
    always @(*) begin
        case (dmem_access)
            `LD_B: case(addr%4)
                2'b00:rd_out = {{24{rd_in[ 7]}},rd_in[ 7: 0]};
                2'b01:rd_out = {{24{rd_in[15]}},rd_in[15: 8]};
                2'b10:rd_out = {{24{rd_in[23]}},rd_in[23:16]};
                2'b11:rd_out = {{24{rd_in[31]}},rd_in[31:24]};
            endcase
            `LD_H: case(addr%4)
                2'b00:rd_out = {{16{rd_in[15]}},rd_in[15: 0]};
                2'b01:rd_out = 32'b0;
                2'b10:rd_out = {{16{rd_in[31]}},rd_in[31:16]};
                2'b11:rd_out = 32'b0;
            endcase
            `LD_W: rd_out = (addr%4==2'b0)?rd_in:32'b0;
            `LD_BU: case(addr%4)
                2'b00:rd_out = {24'b0,rd_in[ 7: 0]};
                2'b01:rd_out = {24'b0,rd_in[15: 8]};
                2'b10:rd_out = {24'b0,rd_in[23:16]};
                2'b11:rd_out = {24'b0,rd_in[31:24]};
            endcase
            `LD_HU: case(addr%4)
                2'b00:rd_out = {16'b0,rd_in[15: 0]};
                2'b01:rd_out = 32'b0;
                2'b10:rd_out = {16'b0,rd_in[31:16]};
                2'b11:rd_out = 32'b0;
            endcase
            default: rd_out = 32'b0;
        endcase
    end
    //写入指令
    always @(*)begin
        case(dmem_access)
            `ST_B: case(addr%4)
                2'b00:wd_out = {rd_in[31: 8],wd_in[ 7: 0]};
                2'b01:wd_out = {rd_in[31:16],wd_in[ 7: 0],rd_in[ 7: 0]};
                2'b10:wd_out = {rd_in[31:24],wd_in[ 7: 0],rd_in[15: 0]};
                2'b11:wd_out = {wd_in[ 7: 0],rd_in[23: 0]};
            endcase
            `ST_H: case(addr%4)
                2'b00:wd_out = {rd_in[31:16],wd_in[15: 0]};
                2'b01:wd_out = rd_in;
                2'b10:wd_out = {wd_in[15: 0],rd_in[15: 0]};
                2'b11:wd_out = rd_in;
            endcase
            `ST_W: wd_out = (addr%4==2'b0)?wd_in:rd_in;
            default: wd_out = rd_in;
        endcase
    end

endmodule
