module SEG_REG (
    input                   [ 0 : 0]        clk,
    input                   [ 0 : 0]        rst,
    input                   [ 0 : 0]        en,
    input                   [ 0 : 0]        flush,
    input                   [ 0 : 0]        stall,
    /* COMMIT */
    input                   [ 0 : 0]        commit_in,
    output       reg        [ 0 : 0]        commit_out,
    /* IF */
    //PC
    input                   [31 : 0]        pc_in,
    //IM
    input                   [31 : 0]        inst_in,
    //PCADD4
    input                   [31 : 0]        pcadd4_in,
    //output
    output       reg        [31 : 0]        pc_out,
    output       reg        [31 : 0]        inst_out,
    output       reg        [31 : 0]        pcadd4_out,
    /* ID */
    //DECODER
    input                   [ 4 : 0]            alu_op_in,
    input                   [ 3 : 0]            dmem_access_in,
    input                   [31 : 0]            imm_in,
    input                   [ 4 : 0]            rf_ra0_in,
    input                   [ 4 : 0]            rf_ra1_in,
    input                   [ 4 : 0]            rf_wa_in,
    input                   [ 0 : 0]            rf_we_in,
    input                   [ 1 : 0]            rf_wd_sel_in,
    input                   [ 0 : 0]            dmem_we_in,
    input                   [ 0 : 0]            alu_src0_sel_in,
    input                   [ 0 : 0]            alu_src1_sel_in,
    input                   [ 5 : 0]            br_type_in,



    output       reg        [ 4 : 0]            alu_op_out,
    output       reg        [ 3 : 0]            dmem_access_out,
    output       reg        [31 : 0]            imm_out,
    output       reg        [ 4 : 0]            rf_ra0_out,
    output       reg        [ 4 : 0]            rf_ra1_out,
    output       reg        [ 4 : 0]            rf_wa_out,
    output       reg        [ 0 : 0]            rf_we_out,
    output       reg        [ 1 : 0]            rf_wd_sel_out,
    output       reg        [ 0 : 0]            dmem_we_out,
    output       reg        [ 0 : 0]            alu_src0_sel_out,
    output       reg        [ 0 : 0]            alu_src1_sel_out,
    output       reg        [ 5 : 0]            br_type_out,
    //REG_FILE
    input                   [31 : 0]        rf_rd0_in,
    input                   [31 : 0]        rf_rd1_in,

    output       reg        [31 : 0]        rf_rd0_out,
    output       reg        [31 : 0]        rf_rd1_out,
    /* EX */
    //ALU接口
    input                   [31 : 0]            alu_res_in,
    output      reg         [31 : 0]            alu_res_out,
    /* MEM */
    //SL_UNIT
    input                   [31 : 0]                rd_out_in,
    output      reg         [31 : 0]                rd_out_out,
    input                   [31 : 0]                dmem_wdata_in,
    output      reg         [31 : 0]                dmem_wdata_out
    /* WB */
);

    always @(posedge clk) begin
        if(rst)begin
            commit_out <= 1'b0;
            /* IF */
            pc_out <= 32'h1c00_0000;
            inst_out <= 32'h0;
            pcadd4_out <= 32'h1c00_0000 + 32'd4;
            /* ID */
            //DECODER
            alu_op_out          <= 5'B01001;//ADD
            dmem_access_out     <= 4'b1010;//
            imm_out             <= 32'b0;//
            rf_ra0_out          <= 5'b0
            rf_ra1_out          <= 5'b0
            rf_wa_out           <= 5'b0;//
            rf_we_out           <= 1'b1;
            rf_wd_sel_out       <= 2'b01;
            dmem_we_out         <= 1'b0;
            alu_src0_sel_out    <= 1'b0; 
            alu_src1_sel_out    <= 1'b1; 
            br_type_out         <= 6'b0;
            //REG_FILE
            rf_rd0_out <= 32'b0;
            rf_rd1_out <= 32'b0;
            /* EXE */
            //ALU
            alu_res_out <= 32'b0;
            /* MEM */
            //SL_UNIT
            rd_out_out <= 32'b0;
            dmem_wdata_out <= 32'b0;
            /* WB */
        end
        else if(en)begin
            if(flush)begin
                commit_out <= 1'b0;
                /* IF */
                pc_out <= 32'h1c00_0000;
                inst_out <= 32'h0;
                pcadd4_out <= 32'h1c00_0000 + 32'd4;
                /* ID */
                //DECODER
                alu_op_out          <= 5'B01001;//ADD
                dmem_access_out     <= 4'b1010;//
                imm_out             <= 32'b0;//
                rf_ra0_out          <= 5'b0;
                rf_ra1_out          <= 5'b0;
                rf_wa_out           <= 5'b0;//
                rf_we_out           <= 1'b1;
                rf_wd_sel_out       <= 2'b01;
                dmem_we_out         <= 1'b0;
                alu_src0_sel_out    <= 1'b0; 
                alu_src1_sel_out    <= 1'b1; 
                br_type_out         <= 6'b0;
                //REG_FILE
                rf_rd0_out <= 32'b0;
                rf_rd1_out <= 32'b0;
                /* EXE */
                //ALU
                alu_res_out <= 32'b0;
                /* MEM */
                //SL_UNIT
                rd_out_out <= 32'b0;
                dmem_wdata_out <= 32'b0;
                /* WB */
            end
            else if(stall)begin
                commit_out <= commit_out;
                /* IF */
                pc_out <= pc_out;
                inst_out <= inst_out;
                pcadd4_out <= pcadd4_out;
                /* ID */
                //DECODER
                alu_op_out          <= alu_op_out;
                dmem_access_out     <= dmem_access_out;
                imm_out             <= imm_out;
                rf_ra0_out          <= rf_ra0_out;
                rf_ra1_out          <= rf_ra1_out;
                rf_wa_out           <= rf_wa_out;
                rf_we_out           <= rf_we_out;
                rf_wd_sel_out       <= rf_wd_sel_out;
                dmem_we_out         <= dmem_we_out;
                alu_src0_sel_out    <= alu_src0_sel_out; 
                alu_src1_sel_out    <= alu_src1_sel_out; 
                br_type_out         <= br_type_out;
                //REG_FILE
                rf_rd0_out <= rf_rd0_out;
                rf_rd1_out <= rf_rd1_out;
                /* EXE */
                //ALU
                alu_res_out <= alu_res_out;
                /* MEM */
                //SL_UNIT
                rd_out_out <= rd_out_out;
                dmem_wdata_out <= dmem_wdata_out;
                /* WB */
            end
            else begin
                commit_out <= commit_in;
                /* IF */
                pc_out <= pc_in;
                inst_out <= inst_in;
                pcadd4_out <= pcadd4_in;
                /* ID */
                //DECODER
                alu_op_out          <= alu_op_in;
                dmem_access_out     <= dmem_access_in;
                imm_out             <= imm_in;
                rf_ra0_out          <= rf_ra0_in;
                rf_ra1_out          <= rf_ra1_in;
                rf_wa_out           <= rf_wa_in;
                rf_we_out           <= rf_we_in;
                rf_wd_sel_out       <= rf_wd_sel_in;
                dmem_we_out         <= dmem_we_in;
                alu_src0_sel_out    <= alu_src0_sel_in; 
                alu_src1_sel_out    <= alu_src1_sel_in; 
                br_type_out         <= br_type_in;
                //REG_FILE
                rf_rd0_out <= rf_rd0_in;
                rf_rd1_out <= rf_rd1_in;
                /* EXE */
                //ALU
                alu_res_out <= alu_res_in;
                /* MEM */
                //SL_UNIT
                rd_out_out <= rd_out_in;
                dmem_wdata_out <= dmem_wdata_in;
                /* WB */
            end
        end
        else begin
            commit_out <= commit_out;
            /* IF */
            pc_out <= pc_out;
            inst_out <= inst_out;
            pcadd4_out <= pcadd4_out;
            /* ID */
            //DECODER
            alu_op_out          <= alu_op_out;
            dmem_access_out     <= dmem_access_out;
            imm_out             <= imm_out;
            rf_ra0_out          <= rf_ra0_out;
            rf_ra1_out          <= rf_ra1_out;
            rf_wa_out           <= rf_wa_out;
            rf_we_out           <= rf_we_out;
            rf_wd_sel_out       <= rf_wd_sel_out;
            dmem_we_out         <= dmem_we_out;
            alu_src0_sel_out    <= alu_src0_sel_out; 
            alu_src1_sel_out    <= alu_src1_sel_out; 
            br_type_out         <= br_type_out;
            //REG_FILE
            rf_rd0_out <= rf_rd0_out;
            rf_rd1_out <= rf_rd1_out;
            /* EXE */
            //ALU
            alu_res_out <= alu_res_out;
            /* MEM */
            //SL_UNIT
            rd_out_out <= rd_out_out;
            dmem_wdata_out <= dmem_wdata_out;
            /* WB */
        end
    end

endmodule