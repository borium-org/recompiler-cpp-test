#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__ClassFormatError.h"
#include "java__lang__String.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionAALOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionAASTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionACONST_NULL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionALOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionANEWARRAY.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionARETURN.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionARRAYLENGTH.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionASTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionATHROW.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionBALOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionBASTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionBIPUSH.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionCALOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionCASTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionCHECKCAST.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionD2F.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionD2I.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionD2L.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDADD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDALOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDASTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDCMPG.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDCMPL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDCONST.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDDIV.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDLOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDMUL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDNEG.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDREM.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDRETURN.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDSTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDSUB.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDUP.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDUP2.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDUP2_X1.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDUP2_X2.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDUP_X1.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDUP_X2.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionF2D.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionF2I.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionF2L.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFADD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFALOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFASTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFCMPG.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFCMPL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFCONST.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFDIV.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFLOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFMUL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFNEG.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFREM.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFRETURN.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFSTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFSUB.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionGETFIELD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionGETSTATIC.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionGOTO.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionGOTO_W.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionI2B.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionI2C.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionI2D.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionI2F.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionI2L.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionI2S.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIADD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIALOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIAND.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIASTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionICONST.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIDIV.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIFEQ.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIFGE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIFGT.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIFLE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIFLT.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIFNE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIFNONNULL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIFNULL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIF_ACMPEQ.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIF_ACMPNE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIF_ICMPEQ.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIF_ICMPGE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIF_ICMPGT.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIF_ICMPLE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIF_ICMPLT.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIF_ICMPNE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIINC.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionILOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIMUL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionINEG.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionINSTANCEOF.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionINVOKEDYNAMIC.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionINVOKEINTERFACE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionINVOKESPECIAL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionINVOKESTATIC.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionINVOKEVIRTUAL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIOR.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIREM.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIRETURN.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionISHL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionISHR.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionISTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionISUB.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIUSHR.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIXOR.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionJSR.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionJSR_W.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionL2D.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionL2F.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionL2I.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLADD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLALOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLAND.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLASTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLCMP.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLCONST.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLDC.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLDC2_W.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLDC_W.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLDIV.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLLOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLMUL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLNEG.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLOOKUPSWITCH.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLOR.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLREM.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLRETURN.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLSHL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLSHR.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLSTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLSUB.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLUSHR.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLXOR.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionMONITORENTER.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionMONITOREXIT.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionMULTIANEWARRAY.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionNEW.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionNEWARRAY.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionNOP.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionPOP.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionPOP2.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionPUTFIELD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionPUTSTATIC.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionRET.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionRETURN.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionSALOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionSASTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionSIPUSH.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionSWAP.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionTABLESWITCH.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionWIDE.h"

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> Instruction::__thisClassStatic;

	int Instruction::NOP = 0;
	int Instruction::ACONST_NULL = 1;
	int Instruction::ICONST_M1 = 2;
	int Instruction::ICONST_0 = 3;
	int Instruction::ICONST_1 = 4;
	int Instruction::ICONST_2 = 5;
	int Instruction::ICONST_3 = 6;
	int Instruction::ICONST_4 = 7;
	int Instruction::ICONST_5 = 8;
	int Instruction::LCONST_0 = 9;
	int Instruction::LCONST_1 = 10;
	int Instruction::FCONST_0 = 11;
	int Instruction::FCONST_1 = 12;
	int Instruction::FCONST_2 = 13;
	int Instruction::DCONST_0 = 14;
	int Instruction::DCONST_1 = 15;
	int Instruction::BIPUSH = 16;
	int Instruction::SIPUSH = 17;
	int Instruction::LDC = 18;
	int Instruction::LDC_W = 19;
	int Instruction::LDC2_W = 20;
	int Instruction::ILOAD = 21;
	int Instruction::LLOAD = 22;
	int Instruction::FLOAD = 23;
	int Instruction::DLOAD = 24;
	int Instruction::ALOAD = 25;
	int Instruction::ILOAD_0 = 26;
	int Instruction::ILOAD_1 = 27;
	int Instruction::ILOAD_2 = 28;
	int Instruction::ILOAD_3 = 29;
	int Instruction::LLOAD_0 = 30;
	int Instruction::LLOAD_1 = 31;
	int Instruction::LLOAD_2 = 32;
	int Instruction::LLOAD_3 = 33;
	int Instruction::FLOAD_0 = 34;
	int Instruction::FLOAD_1 = 35;
	int Instruction::FLOAD_2 = 36;
	int Instruction::FLOAD_3 = 37;
	int Instruction::DLOAD_0 = 38;
	int Instruction::DLOAD_1 = 39;
	int Instruction::DLOAD_2 = 40;
	int Instruction::DLOAD_3 = 41;
	int Instruction::ALOAD_0 = 42;
	int Instruction::ALOAD_1 = 43;
	int Instruction::ALOAD_2 = 44;
	int Instruction::ALOAD_3 = 45;
	int Instruction::IALOAD = 46;
	int Instruction::LALOAD = 47;
	int Instruction::FALOAD = 48;
	int Instruction::DALOAD = 49;
	int Instruction::AALOAD = 50;
	int Instruction::BALOAD = 51;
	int Instruction::CALOAD = 52;
	int Instruction::SALOAD = 53;
	int Instruction::ISTORE = 54;
	int Instruction::LSTORE = 55;
	int Instruction::FSTORE = 56;
	int Instruction::DSTORE = 57;
	int Instruction::ASTORE = 58;
	int Instruction::ISTORE_0 = 59;
	int Instruction::ISTORE_1 = 60;
	int Instruction::ISTORE_2 = 61;
	int Instruction::ISTORE_3 = 62;
	int Instruction::LSTORE_0 = 63;
	int Instruction::LSTORE_1 = 64;
	int Instruction::LSTORE_2 = 65;
	int Instruction::LSTORE_3 = 66;
	int Instruction::FSTORE_0 = 67;
	int Instruction::FSTORE_1 = 68;
	int Instruction::FSTORE_2 = 69;
	int Instruction::FSTORE_3 = 70;
	int Instruction::DSTORE_0 = 71;
	int Instruction::DSTORE_1 = 72;
	int Instruction::DSTORE_2 = 73;
	int Instruction::DSTORE_3 = 74;
	int Instruction::ASTORE_0 = 75;
	int Instruction::ASTORE_1 = 76;
	int Instruction::ASTORE_2 = 77;
	int Instruction::ASTORE_3 = 78;
	int Instruction::IASTORE = 79;
	int Instruction::LASTORE = 80;
	int Instruction::FASTORE = 81;
	int Instruction::DASTORE = 82;
	int Instruction::AASTORE = 83;
	int Instruction::BASTORE = 84;
	int Instruction::CASTORE = 85;
	int Instruction::SASTORE = 86;
	int Instruction::POP = 87;
	int Instruction::POP2 = 88;
	int Instruction::DUP = 89;
	int Instruction::DUP_X1 = 90;
	int Instruction::DUP_X2 = 91;
	int Instruction::DUP2 = 92;
	int Instruction::DUP2_X1 = 93;
	int Instruction::DUP2_X2 = 94;
	int Instruction::SWAP = 95;
	int Instruction::IADD = 96;
	int Instruction::LADD = 97;
	int Instruction::FADD = 98;
	int Instruction::DADD = 99;
	int Instruction::ISUB = 100;
	int Instruction::LSUB = 101;
	int Instruction::FSUB = 102;
	int Instruction::DSUB = 103;
	int Instruction::IMUL = 104;
	int Instruction::LMUL = 105;
	int Instruction::FMUL = 106;
	int Instruction::DMUL = 107;
	int Instruction::IDIV = 108;
	int Instruction::LDIV = 109;
	int Instruction::FDIV = 110;
	int Instruction::DDIV = 111;
	int Instruction::IREM = 112;
	int Instruction::LREM = 113;
	int Instruction::FREM = 114;
	int Instruction::DREM = 115;
	int Instruction::INEG = 116;
	int Instruction::LNEG = 117;
	int Instruction::FNEG = 118;
	int Instruction::DNEG = 119;
	int Instruction::ISHL = 120;
	int Instruction::LSHL = 121;
	int Instruction::ISHR = 122;
	int Instruction::LSHR = 123;
	int Instruction::IUSHR = 124;
	int Instruction::LUSHR = 125;
	int Instruction::IAND = 126;
	int Instruction::LAND = 127;
	int Instruction::IOR = 128;
	int Instruction::LOR = 129;
	int Instruction::IXOR = 130;
	int Instruction::LXOR = 131;
	int Instruction::IINC = 132;
	int Instruction::I2L = 133;
	int Instruction::I2F = 134;
	int Instruction::I2D = 135;
	int Instruction::L2I = 136;
	int Instruction::L2F = 137;
	int Instruction::L2D = 138;
	int Instruction::F2I = 139;
	int Instruction::F2L = 140;
	int Instruction::F2D = 141;
	int Instruction::D2I = 142;
	int Instruction::D2L = 143;
	int Instruction::D2F = 144;
	int Instruction::I2B = 145;
	int Instruction::I2C = 146;
	int Instruction::I2S = 147;
	int Instruction::LCMP = 148;
	int Instruction::FCMPL = 149;
	int Instruction::FCMPG = 150;
	int Instruction::DCMPL = 151;
	int Instruction::DCMPG = 152;
	int Instruction::IFEQ = 153;
	int Instruction::IFNE = 154;
	int Instruction::IFLT = 155;
	int Instruction::IFGE = 156;
	int Instruction::IFGT = 157;
	int Instruction::IFLE = 158;
	int Instruction::IF_ICMPEQ = 159;
	int Instruction::IF_ICMPNE = 160;
	int Instruction::IF_ICMPLT = 161;
	int Instruction::IF_ICMPGE = 162;
	int Instruction::IF_ICMPGT = 163;
	int Instruction::IF_ICMPLE = 164;
	int Instruction::IF_ACMPEQ = 165;
	int Instruction::IF_ACMPNE = 166;
	int Instruction::GOTO = 167;
	int Instruction::JSR = 168;
	int Instruction::RET = 169;
	int Instruction::TABLESWITCH = 170;
	int Instruction::LOOKUPSWITCH = 171;
	int Instruction::IRETURN = 172;
	int Instruction::LRETURN = 173;
	int Instruction::FRETURN = 174;
	int Instruction::DRETURN = 175;
	int Instruction::ARETURN = 176;
	int Instruction::RETURN = 177;
	int Instruction::GETSTATIC = 178;
	int Instruction::PUTSTATIC = 179;
	int Instruction::GETFIELD = 180;
	int Instruction::PUTFIELD = 181;
	int Instruction::INVOKEVIRTUAL = 182;
	int Instruction::INVOKESPECIAL = 183;
	int Instruction::INVOKESTATIC = 184;
	int Instruction::INVOKEINTERFACE = 185;
	int Instruction::INVOKEDYNAMIC = 186;
	int Instruction::NEW = 187;
	int Instruction::NEWARRAY = 188;
	int Instruction::ANEWARRAY = 189;
	int Instruction::ARRAYLENGTH = 190;
	int Instruction::ATHROW = 191;
	int Instruction::CHECKCAST = 192;
	int Instruction::INSTANCEOF = 193;
	int Instruction::MONITORENTER = 194;
	int Instruction::MONITOREXIT = 195;
	int Instruction::WIDE = 196;
	int Instruction::MULTIANEWARRAY = 197;
	int Instruction::IFNULL = 198;
	int Instruction::IFNONNULL = 199;
	int Instruction::GOTO_W = 200;
	int Instruction::JSR_W = 201;
	int Instruction::BREAKPOINT = 202;
	int Instruction::IMPDEP1 = 254;
	int Instruction::IMPDEP2 = 255;

	void Instruction::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::Instruction",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	Instruction::Instruction() :
		Object() //
		, address(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	Pointer<Instruction> Instruction::read(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp)
	{
		__ClassInit();

		int code_0005 = 0;
		Pointer<ClassFormatError> temp_0011;
		Pointer<InstructionNOP> temp_0350;
		Pointer<InstructionACONST_NULL> temp_0358;
		Pointer<InstructionICONST> temp_0361;
		Pointer<InstructionICONST> temp_036A;
		Pointer<InstructionICONST> temp_0373;
		Pointer<InstructionICONST> temp_037C;
		Pointer<InstructionICONST> temp_0385;
		Pointer<InstructionICONST> temp_038E;
		Pointer<InstructionICONST> temp_0397;
		Pointer<InstructionLCONST> temp_03A0;
		Pointer<InstructionLCONST> temp_03A9;
		Pointer<InstructionFCONST> temp_03B2;
		Pointer<InstructionFCONST> temp_03BB;
		Pointer<InstructionFCONST> temp_03C6;
		Pointer<InstructionDCONST> temp_03CF;
		Pointer<InstructionDCONST> temp_03D8;
		Pointer<InstructionBIPUSH> temp_03E1;
		Pointer<InstructionSIPUSH> temp_03EA;
		Pointer<InstructionLDC> temp_03F4;
		Pointer<InstructionLDC_W> temp_03FE;
		Pointer<InstructionLDC2_W> temp_0408;
		Pointer<InstructionILOAD> temp_0412;
		Pointer<InstructionLLOAD> temp_041C;
		Pointer<InstructionFLOAD> temp_0426;
		Pointer<InstructionDLOAD> temp_0430;
		Pointer<InstructionALOAD> temp_043A;
		Pointer<InstructionILOAD> temp_0443;
		Pointer<InstructionILOAD> temp_044C;
		Pointer<InstructionILOAD> temp_0455;
		Pointer<InstructionILOAD> temp_045E;
		Pointer<InstructionLLOAD> temp_0467;
		Pointer<InstructionLLOAD> temp_0470;
		Pointer<InstructionLLOAD> temp_0479;
		Pointer<InstructionLLOAD> temp_0482;
		Pointer<InstructionFLOAD> temp_048B;
		Pointer<InstructionFLOAD> temp_0494;
		Pointer<InstructionFLOAD> temp_049D;
		Pointer<InstructionFLOAD> temp_04A6;
		Pointer<InstructionDLOAD> temp_04AF;
		Pointer<InstructionDLOAD> temp_04B8;
		Pointer<InstructionDLOAD> temp_04C1;
		Pointer<InstructionDLOAD> temp_04CA;
		Pointer<InstructionALOAD> temp_04D3;
		Pointer<InstructionALOAD> temp_04DC;
		Pointer<InstructionALOAD> temp_04E5;
		Pointer<InstructionALOAD> temp_04EE;
		Pointer<InstructionIALOAD> temp_04F6;
		Pointer<InstructionLALOAD> temp_04FE;
		Pointer<InstructionFALOAD> temp_0506;
		Pointer<InstructionDALOAD> temp_050E;
		Pointer<InstructionAALOAD> temp_0516;
		Pointer<InstructionBALOAD> temp_051E;
		Pointer<InstructionCALOAD> temp_0526;
		Pointer<InstructionSALOAD> temp_052E;
		Pointer<InstructionISTORE> temp_0538;
		Pointer<InstructionLSTORE> temp_0542;
		Pointer<InstructionFSTORE> temp_054C;
		Pointer<InstructionDSTORE> temp_0556;
		Pointer<InstructionASTORE> temp_0560;
		Pointer<InstructionISTORE> temp_0569;
		Pointer<InstructionISTORE> temp_0572;
		Pointer<InstructionISTORE> temp_057B;
		Pointer<InstructionISTORE> temp_0584;
		Pointer<InstructionLSTORE> temp_058D;
		Pointer<InstructionLSTORE> temp_0596;
		Pointer<InstructionLSTORE> temp_059F;
		Pointer<InstructionLSTORE> temp_05A8;
		Pointer<InstructionFSTORE> temp_05B1;
		Pointer<InstructionFSTORE> temp_05BA;
		Pointer<InstructionFSTORE> temp_05C3;
		Pointer<InstructionFSTORE> temp_05CC;
		Pointer<InstructionDSTORE> temp_05D5;
		Pointer<InstructionDSTORE> temp_05DE;
		Pointer<InstructionDSTORE> temp_05E7;
		Pointer<InstructionDSTORE> temp_05F0;
		Pointer<InstructionASTORE> temp_05F9;
		Pointer<InstructionASTORE> temp_0602;
		Pointer<InstructionASTORE> temp_060B;
		Pointer<InstructionASTORE> temp_0614;
		Pointer<InstructionIASTORE> temp_061C;
		Pointer<InstructionLASTORE> temp_0624;
		Pointer<InstructionFASTORE> temp_062C;
		Pointer<InstructionDASTORE> temp_0634;
		Pointer<InstructionAASTORE> temp_063C;
		Pointer<InstructionBASTORE> temp_0644;
		Pointer<InstructionCASTORE> temp_064C;
		Pointer<InstructionSASTORE> temp_0654;
		Pointer<InstructionPOP> temp_065C;
		Pointer<InstructionPOP2> temp_0664;
		Pointer<InstructionDUP> temp_066C;
		Pointer<InstructionDUP_X1> temp_0674;
		Pointer<InstructionDUP_X2> temp_067C;
		Pointer<InstructionDUP2> temp_0684;
		Pointer<InstructionDUP2_X1> temp_068C;
		Pointer<InstructionDUP2_X2> temp_0694;
		Pointer<InstructionSWAP> temp_069C;
		Pointer<InstructionIADD> temp_06A4;
		Pointer<InstructionLADD> temp_06AC;
		Pointer<InstructionFADD> temp_06B4;
		Pointer<InstructionDADD> temp_06BC;
		Pointer<InstructionISUB> temp_06C4;
		Pointer<InstructionLSUB> temp_06CC;
		Pointer<InstructionFSUB> temp_06D4;
		Pointer<InstructionDSUB> temp_06DC;
		Pointer<InstructionIMUL> temp_06E4;
		Pointer<InstructionLMUL> temp_06EC;
		Pointer<InstructionFMUL> temp_06F4;
		Pointer<InstructionDMUL> temp_06FC;
		Pointer<InstructionIDIV> temp_0704;
		Pointer<InstructionLDIV> temp_070C;
		Pointer<InstructionFDIV> temp_0714;
		Pointer<InstructionDDIV> temp_071C;
		Pointer<InstructionIREM> temp_0724;
		Pointer<InstructionLREM> temp_072C;
		Pointer<InstructionFREM> temp_0734;
		Pointer<InstructionDREM> temp_073C;
		Pointer<InstructionINEG> temp_0744;
		Pointer<InstructionLNEG> temp_074C;
		Pointer<InstructionFNEG> temp_0754;
		Pointer<InstructionDNEG> temp_075C;
		Pointer<InstructionISHL> temp_0764;
		Pointer<InstructionLSHL> temp_076C;
		Pointer<InstructionISHR> temp_0774;
		Pointer<InstructionLSHR> temp_077C;
		Pointer<InstructionIUSHR> temp_0784;
		Pointer<InstructionLUSHR> temp_078C;
		Pointer<InstructionIAND> temp_0794;
		Pointer<InstructionLAND> temp_079C;
		Pointer<InstructionIOR> temp_07A4;
		Pointer<InstructionLOR> temp_07AC;
		Pointer<InstructionIXOR> temp_07B4;
		Pointer<InstructionLXOR> temp_07BC;
		Pointer<InstructionIINC> temp_07C6;
		Pointer<InstructionI2L> temp_07CE;
		Pointer<InstructionI2F> temp_07D6;
		Pointer<InstructionI2D> temp_07DE;
		Pointer<InstructionL2I> temp_07E6;
		Pointer<InstructionL2F> temp_07EE;
		Pointer<InstructionL2D> temp_07F6;
		Pointer<InstructionF2I> temp_07FE;
		Pointer<InstructionF2L> temp_0806;
		Pointer<InstructionF2D> temp_080E;
		Pointer<InstructionD2I> temp_0816;
		Pointer<InstructionD2L> temp_081E;
		Pointer<InstructionD2F> temp_0826;
		Pointer<InstructionI2B> temp_082E;
		Pointer<InstructionI2C> temp_0836;
		Pointer<InstructionI2S> temp_083E;
		Pointer<InstructionLCMP> temp_0846;
		Pointer<InstructionFCMPL> temp_084E;
		Pointer<InstructionFCMPG> temp_0856;
		Pointer<InstructionDCMPL> temp_085E;
		Pointer<InstructionDCMPG> temp_0866;
		Pointer<InstructionIFEQ> temp_086F;
		Pointer<InstructionIFNE> temp_0878;
		Pointer<InstructionIFLT> temp_0881;
		Pointer<InstructionIFGE> temp_088A;
		Pointer<InstructionIFGT> temp_0893;
		Pointer<InstructionIFLE> temp_089C;
		Pointer<InstructionIF_ICMPEQ> temp_08A5;
		Pointer<InstructionIF_ICMPNE> temp_08AE;
		Pointer<InstructionIF_ICMPLT> temp_08B7;
		Pointer<InstructionIF_ICMPGE> temp_08C0;
		Pointer<InstructionIF_ICMPGT> temp_08C9;
		Pointer<InstructionIF_ICMPLE> temp_08D2;
		Pointer<InstructionIF_ACMPEQ> temp_08DB;
		Pointer<InstructionIF_ACMPNE> temp_08E4;
		Pointer<InstructionGOTO> temp_08ED;
		Pointer<InstructionJSR> temp_08F6;
		Pointer<InstructionRET> temp_0900;
		Pointer<InstructionTABLESWITCH> temp_0909;
		Pointer<InstructionLOOKUPSWITCH> temp_0912;
		Pointer<InstructionIRETURN> temp_091A;
		Pointer<InstructionLRETURN> temp_0922;
		Pointer<InstructionFRETURN> temp_092A;
		Pointer<InstructionDRETURN> temp_0932;
		Pointer<InstructionARETURN> temp_093A;
		Pointer<InstructionRETURN> temp_0942;
		Pointer<InstructionGETSTATIC> temp_094C;
		Pointer<InstructionPUTSTATIC> temp_0956;
		Pointer<InstructionGETFIELD> temp_0960;
		Pointer<InstructionPUTFIELD> temp_096A;
		Pointer<InstructionINVOKEVIRTUAL> temp_0974;
		Pointer<InstructionINVOKESPECIAL> temp_097E;
		Pointer<InstructionINVOKESTATIC> temp_0988;
		Pointer<InstructionINVOKEINTERFACE> temp_0992;
		Pointer<InstructionINVOKEDYNAMIC> temp_099B;
		Pointer<InstructionNEW> temp_09A5;
		Pointer<InstructionNEWARRAY> temp_09AE;
		Pointer<InstructionANEWARRAY> temp_09B8;
		Pointer<InstructionARRAYLENGTH> temp_09C0;
		Pointer<InstructionATHROW> temp_09C8;
		Pointer<InstructionCHECKCAST> temp_09D2;
		Pointer<InstructionINSTANCEOF> temp_09DC;
		Pointer<InstructionMONITORENTER> temp_09E4;
		Pointer<InstructionMONITOREXIT> temp_09EC;
		Pointer<InstructionWIDE> temp_09F5;
		Pointer<InstructionMULTIANEWARRAY> temp_09FE;
		Pointer<InstructionIFNULL> temp_0A07;
		Pointer<InstructionIFNONNULL> temp_0A10;
		Pointer<InstructionGOTO_W> temp_0A19;
		Pointer<InstructionJSR_W> temp_0A22;
		code_0005 = in->u1();
		if ((code_0005) != (-1))
			goto L0015;
		temp_0011 = new ClassFormatError(createString("Read error"));
		throw temp_0011;
	L0015: //
		switch (code_0005)
		{
		case 0:
			goto L034C;
		case 1:
			goto L0354;
		case 2:
			goto L035C;
		case 3:
			goto L0365;
		case 4:
			goto L036E;
		case 5:
			goto L0377;
		case 6:
			goto L0380;
		case 7:
			goto L0389;
		case 8:
			goto L0392;
		case 9:
			goto L039B;
		case 10:
			goto L03A4;
		case 11:
			goto L03AD;
		case 12:
			goto L03B6;
		case 13:
			goto L03BF;
		case 14:
			goto L03CA;
		case 15:
			goto L03D3;
		case 16:
			goto L03DC;
		case 17:
			goto L03E5;
		case 18:
			goto L03EE;
		case 19:
			goto L03F8;
		case 20:
			goto L0402;
		case 21:
			goto L040C;
		case 22:
			goto L0416;
		case 23:
			goto L0420;
		case 24:
			goto L042A;
		case 25:
			goto L0434;
		case 26:
			goto L043E;
		case 27:
			goto L0447;
		case 28:
			goto L0450;
		case 29:
			goto L0459;
		case 30:
			goto L0462;
		case 31:
			goto L046B;
		case 32:
			goto L0474;
		case 33:
			goto L047D;
		case 34:
			goto L0486;
		case 35:
			goto L048F;
		case 36:
			goto L0498;
		case 37:
			goto L04A1;
		case 38:
			goto L04AA;
		case 39:
			goto L04B3;
		case 40:
			goto L04BC;
		case 41:
			goto L04C5;
		case 42:
			goto L04CE;
		case 43:
			goto L04D7;
		case 44:
			goto L04E0;
		case 45:
			goto L04E9;
		case 46:
			goto L04F2;
		case 47:
			goto L04FA;
		case 48:
			goto L0502;
		case 49:
			goto L050A;
		case 50:
			goto L0512;
		case 51:
			goto L051A;
		case 52:
			goto L0522;
		case 53:
			goto L052A;
		case 54:
			goto L0532;
		case 55:
			goto L053C;
		case 56:
			goto L0546;
		case 57:
			goto L0550;
		case 58:
			goto L055A;
		case 59:
			goto L0564;
		case 60:
			goto L056D;
		case 61:
			goto L0576;
		case 62:
			goto L057F;
		case 63:
			goto L0588;
		case 64:
			goto L0591;
		case 65:
			goto L059A;
		case 66:
			goto L05A3;
		case 67:
			goto L05AC;
		case 68:
			goto L05B5;
		case 69:
			goto L05BE;
		case 70:
			goto L05C7;
		case 71:
			goto L05D0;
		case 72:
			goto L05D9;
		case 73:
			goto L05E2;
		case 74:
			goto L05EB;
		case 75:
			goto L05F4;
		case 76:
			goto L05FD;
		case 77:
			goto L0606;
		case 78:
			goto L060F;
		case 79:
			goto L0618;
		case 80:
			goto L0620;
		case 81:
			goto L0628;
		case 82:
			goto L0630;
		case 83:
			goto L0638;
		case 84:
			goto L0640;
		case 85:
			goto L0648;
		case 86:
			goto L0650;
		case 87:
			goto L0658;
		case 88:
			goto L0660;
		case 89:
			goto L0668;
		case 90:
			goto L0670;
		case 91:
			goto L0678;
		case 92:
			goto L0680;
		case 93:
			goto L0688;
		case 94:
			goto L0690;
		case 95:
			goto L0698;
		case 96:
			goto L06A0;
		case 97:
			goto L06A8;
		case 98:
			goto L06B0;
		case 99:
			goto L06B8;
		case 100:
			goto L06C0;
		case 101:
			goto L06C8;
		case 102:
			goto L06D0;
		case 103:
			goto L06D8;
		case 104:
			goto L06E0;
		case 105:
			goto L06E8;
		case 106:
			goto L06F0;
		case 107:
			goto L06F8;
		case 108:
			goto L0700;
		case 109:
			goto L0708;
		case 110:
			goto L0710;
		case 111:
			goto L0718;
		case 112:
			goto L0720;
		case 113:
			goto L0728;
		case 114:
			goto L0730;
		case 115:
			goto L0738;
		case 116:
			goto L0740;
		case 117:
			goto L0748;
		case 118:
			goto L0750;
		case 119:
			goto L0758;
		case 120:
			goto L0760;
		case 121:
			goto L0768;
		case 122:
			goto L0770;
		case 123:
			goto L0778;
		case 124:
			goto L0780;
		case 125:
			goto L0788;
		case 126:
			goto L0790;
		case 127:
			goto L0798;
		case 128:
			goto L07A0;
		case 129:
			goto L07A8;
		case 130:
			goto L07B0;
		case 131:
			goto L07B8;
		case 132:
			goto L07C0;
		case 133:
			goto L07CA;
		case 134:
			goto L07D2;
		case 135:
			goto L07DA;
		case 136:
			goto L07E2;
		case 137:
			goto L07EA;
		case 138:
			goto L07F2;
		case 139:
			goto L07FA;
		case 140:
			goto L0802;
		case 141:
			goto L080A;
		case 142:
			goto L0812;
		case 143:
			goto L081A;
		case 144:
			goto L0822;
		case 145:
			goto L082A;
		case 146:
			goto L0832;
		case 147:
			goto L083A;
		case 148:
			goto L0842;
		case 149:
			goto L084A;
		case 150:
			goto L0852;
		case 151:
			goto L085A;
		case 152:
			goto L0862;
		case 153:
			goto L086A;
		case 154:
			goto L0873;
		case 155:
			goto L087C;
		case 156:
			goto L0885;
		case 157:
			goto L088E;
		case 158:
			goto L0897;
		case 159:
			goto L08A0;
		case 160:
			goto L08A9;
		case 161:
			goto L08B2;
		case 162:
			goto L08BB;
		case 163:
			goto L08C4;
		case 164:
			goto L08CD;
		case 165:
			goto L08D6;
		case 166:
			goto L08DF;
		case 167:
			goto L08E8;
		case 168:
			goto L08F1;
		case 169:
			goto L08FA;
		case 170:
			goto L0904;
		case 171:
			goto L090D;
		case 172:
			goto L0916;
		case 173:
			goto L091E;
		case 174:
			goto L0926;
		case 175:
			goto L092E;
		case 176:
			goto L0936;
		case 177:
			goto L093E;
		case 178:
			goto L0946;
		case 179:
			goto L0950;
		case 180:
			goto L095A;
		case 181:
			goto L0964;
		case 182:
			goto L096E;
		case 183:
			goto L0978;
		case 184:
			goto L0982;
		case 185:
			goto L098C;
		case 186:
			goto L0996;
		case 187:
			goto L099F;
		case 188:
			goto L09A9;
		case 189:
			goto L09B2;
		case 190:
			goto L09BC;
		case 191:
			goto L09C4;
		case 192:
			goto L09CC;
		case 193:
			goto L09D6;
		case 194:
			goto L09E0;
		case 195:
			goto L09E8;
		case 196:
			goto L09F0;
		case 197:
			goto L09F9;
		case 198:
			goto L0A02;
		case 199:
			goto L0A0B;
		case 200:
			goto L0A14;
		case 201:
			goto L0A1D;
		default:
			goto L0A26;
		}
	L034C: //
		temp_0350 = new InstructionNOP();
		// ARETURN: Type mismatch
		return temp_0350.getValue();
	L0354: //
		temp_0358 = new InstructionACONST_NULL();
		// ARETURN: Type mismatch
		return temp_0358.getValue();
	L035C: //
		temp_0361 = new InstructionICONST(-1);
		// ARETURN: Type mismatch
		return temp_0361.getValue();
	L0365: //
		temp_036A = new InstructionICONST(0);
		// ARETURN: Type mismatch
		return temp_036A.getValue();
	L036E: //
		temp_0373 = new InstructionICONST(1);
		// ARETURN: Type mismatch
		return temp_0373.getValue();
	L0377: //
		temp_037C = new InstructionICONST(2);
		// ARETURN: Type mismatch
		return temp_037C.getValue();
	L0380: //
		temp_0385 = new InstructionICONST(3);
		// ARETURN: Type mismatch
		return temp_0385.getValue();
	L0389: //
		temp_038E = new InstructionICONST(4);
		// ARETURN: Type mismatch
		return temp_038E.getValue();
	L0392: //
		temp_0397 = new InstructionICONST(5);
		// ARETURN: Type mismatch
		return temp_0397.getValue();
	L039B: //
		temp_03A0 = new InstructionLCONST(0LL);
		// ARETURN: Type mismatch
		return temp_03A0.getValue();
	L03A4: //
		temp_03A9 = new InstructionLCONST(1LL);
		// ARETURN: Type mismatch
		return temp_03A9.getValue();
	L03AD: //
		temp_03B2 = new InstructionFCONST(0.0);
		// ARETURN: Type mismatch
		return temp_03B2.getValue();
	L03B6: //
		temp_03BB = new InstructionFCONST(1.0);
		// ARETURN: Type mismatch
		return temp_03BB.getValue();
	L03BF: //
		temp_03C6 = new InstructionFCONST(2.0);
		// ARETURN: Type mismatch
		return temp_03C6.getValue();
	L03CA: //
		temp_03CF = new InstructionDCONST(0.0);
		// ARETURN: Type mismatch
		return temp_03CF.getValue();
	L03D3: //
		temp_03D8 = new InstructionDCONST(1.0);
		// ARETURN: Type mismatch
		return temp_03D8.getValue();
	L03DC: //
		temp_03E1 = new InstructionBIPUSH(in);
		// ARETURN: Type mismatch
		return temp_03E1.getValue();
	L03E5: //
		temp_03EA = new InstructionSIPUSH(in);
		// ARETURN: Type mismatch
		return temp_03EA.getValue();
	L03EE: //
		temp_03F4 = new InstructionLDC(in, cp);
		// ARETURN: Type mismatch
		return temp_03F4.getValue();
	L03F8: //
		temp_03FE = new InstructionLDC_W(in, cp);
		// ARETURN: Type mismatch
		return temp_03FE.getValue();
	L0402: //
		temp_0408 = new InstructionLDC2_W(in, cp);
		// ARETURN: Type mismatch
		return temp_0408.getValue();
	L040C: //
		temp_0412 = new InstructionILOAD(in, false);
		// ARETURN: Type mismatch
		return temp_0412.getValue();
	L0416: //
		temp_041C = new InstructionLLOAD(in, false);
		// ARETURN: Type mismatch
		return temp_041C.getValue();
	L0420: //
		temp_0426 = new InstructionFLOAD(in, false);
		// ARETURN: Type mismatch
		return temp_0426.getValue();
	L042A: //
		temp_0430 = new InstructionDLOAD(in, false);
		// ARETURN: Type mismatch
		return temp_0430.getValue();
	L0434: //
		temp_043A = new InstructionALOAD(in, false);
		// ARETURN: Type mismatch
		return temp_043A.getValue();
	L043E: //
		temp_0443 = new InstructionILOAD(0);
		// ARETURN: Type mismatch
		return temp_0443.getValue();
	L0447: //
		temp_044C = new InstructionILOAD(1);
		// ARETURN: Type mismatch
		return temp_044C.getValue();
	L0450: //
		temp_0455 = new InstructionILOAD(2);
		// ARETURN: Type mismatch
		return temp_0455.getValue();
	L0459: //
		temp_045E = new InstructionILOAD(3);
		// ARETURN: Type mismatch
		return temp_045E.getValue();
	L0462: //
		temp_0467 = new InstructionLLOAD(0);
		// ARETURN: Type mismatch
		return temp_0467.getValue();
	L046B: //
		temp_0470 = new InstructionLLOAD(1);
		// ARETURN: Type mismatch
		return temp_0470.getValue();
	L0474: //
		temp_0479 = new InstructionLLOAD(2);
		// ARETURN: Type mismatch
		return temp_0479.getValue();
	L047D: //
		temp_0482 = new InstructionLLOAD(3);
		// ARETURN: Type mismatch
		return temp_0482.getValue();
	L0486: //
		temp_048B = new InstructionFLOAD(0);
		// ARETURN: Type mismatch
		return temp_048B.getValue();
	L048F: //
		temp_0494 = new InstructionFLOAD(1);
		// ARETURN: Type mismatch
		return temp_0494.getValue();
	L0498: //
		temp_049D = new InstructionFLOAD(2);
		// ARETURN: Type mismatch
		return temp_049D.getValue();
	L04A1: //
		temp_04A6 = new InstructionFLOAD(3);
		// ARETURN: Type mismatch
		return temp_04A6.getValue();
	L04AA: //
		temp_04AF = new InstructionDLOAD(0);
		// ARETURN: Type mismatch
		return temp_04AF.getValue();
	L04B3: //
		temp_04B8 = new InstructionDLOAD(1);
		// ARETURN: Type mismatch
		return temp_04B8.getValue();
	L04BC: //
		temp_04C1 = new InstructionDLOAD(2);
		// ARETURN: Type mismatch
		return temp_04C1.getValue();
	L04C5: //
		temp_04CA = new InstructionDLOAD(3);
		// ARETURN: Type mismatch
		return temp_04CA.getValue();
	L04CE: //
		temp_04D3 = new InstructionALOAD(0);
		// ARETURN: Type mismatch
		return temp_04D3.getValue();
	L04D7: //
		temp_04DC = new InstructionALOAD(1);
		// ARETURN: Type mismatch
		return temp_04DC.getValue();
	L04E0: //
		temp_04E5 = new InstructionALOAD(2);
		// ARETURN: Type mismatch
		return temp_04E5.getValue();
	L04E9: //
		temp_04EE = new InstructionALOAD(3);
		// ARETURN: Type mismatch
		return temp_04EE.getValue();
	L04F2: //
		temp_04F6 = new InstructionIALOAD();
		// ARETURN: Type mismatch
		return temp_04F6.getValue();
	L04FA: //
		temp_04FE = new InstructionLALOAD();
		// ARETURN: Type mismatch
		return temp_04FE.getValue();
	L0502: //
		temp_0506 = new InstructionFALOAD();
		// ARETURN: Type mismatch
		return temp_0506.getValue();
	L050A: //
		temp_050E = new InstructionDALOAD();
		// ARETURN: Type mismatch
		return temp_050E.getValue();
	L0512: //
		temp_0516 = new InstructionAALOAD();
		// ARETURN: Type mismatch
		return temp_0516.getValue();
	L051A: //
		temp_051E = new InstructionBALOAD();
		// ARETURN: Type mismatch
		return temp_051E.getValue();
	L0522: //
		temp_0526 = new InstructionCALOAD();
		// ARETURN: Type mismatch
		return temp_0526.getValue();
	L052A: //
		temp_052E = new InstructionSALOAD();
		// ARETURN: Type mismatch
		return temp_052E.getValue();
	L0532: //
		temp_0538 = new InstructionISTORE(in, false);
		// ARETURN: Type mismatch
		return temp_0538.getValue();
	L053C: //
		temp_0542 = new InstructionLSTORE(in, false);
		// ARETURN: Type mismatch
		return temp_0542.getValue();
	L0546: //
		temp_054C = new InstructionFSTORE(in, false);
		// ARETURN: Type mismatch
		return temp_054C.getValue();
	L0550: //
		temp_0556 = new InstructionDSTORE(in, false);
		// ARETURN: Type mismatch
		return temp_0556.getValue();
	L055A: //
		temp_0560 = new InstructionASTORE(in, false);
		// ARETURN: Type mismatch
		return temp_0560.getValue();
	L0564: //
		temp_0569 = new InstructionISTORE(0);
		// ARETURN: Type mismatch
		return temp_0569.getValue();
	L056D: //
		temp_0572 = new InstructionISTORE(1);
		// ARETURN: Type mismatch
		return temp_0572.getValue();
	L0576: //
		temp_057B = new InstructionISTORE(2);
		// ARETURN: Type mismatch
		return temp_057B.getValue();
	L057F: //
		temp_0584 = new InstructionISTORE(3);
		// ARETURN: Type mismatch
		return temp_0584.getValue();
	L0588: //
		temp_058D = new InstructionLSTORE(0);
		// ARETURN: Type mismatch
		return temp_058D.getValue();
	L0591: //
		temp_0596 = new InstructionLSTORE(1);
		// ARETURN: Type mismatch
		return temp_0596.getValue();
	L059A: //
		temp_059F = new InstructionLSTORE(2);
		// ARETURN: Type mismatch
		return temp_059F.getValue();
	L05A3: //
		temp_05A8 = new InstructionLSTORE(3);
		// ARETURN: Type mismatch
		return temp_05A8.getValue();
	L05AC: //
		temp_05B1 = new InstructionFSTORE(0);
		// ARETURN: Type mismatch
		return temp_05B1.getValue();
	L05B5: //
		temp_05BA = new InstructionFSTORE(1);
		// ARETURN: Type mismatch
		return temp_05BA.getValue();
	L05BE: //
		temp_05C3 = new InstructionFSTORE(2);
		// ARETURN: Type mismatch
		return temp_05C3.getValue();
	L05C7: //
		temp_05CC = new InstructionFSTORE(3);
		// ARETURN: Type mismatch
		return temp_05CC.getValue();
	L05D0: //
		temp_05D5 = new InstructionDSTORE(0);
		// ARETURN: Type mismatch
		return temp_05D5.getValue();
	L05D9: //
		temp_05DE = new InstructionDSTORE(1);
		// ARETURN: Type mismatch
		return temp_05DE.getValue();
	L05E2: //
		temp_05E7 = new InstructionDSTORE(2);
		// ARETURN: Type mismatch
		return temp_05E7.getValue();
	L05EB: //
		temp_05F0 = new InstructionDSTORE(3);
		// ARETURN: Type mismatch
		return temp_05F0.getValue();
	L05F4: //
		temp_05F9 = new InstructionASTORE(0);
		// ARETURN: Type mismatch
		return temp_05F9.getValue();
	L05FD: //
		temp_0602 = new InstructionASTORE(1);
		// ARETURN: Type mismatch
		return temp_0602.getValue();
	L0606: //
		temp_060B = new InstructionASTORE(2);
		// ARETURN: Type mismatch
		return temp_060B.getValue();
	L060F: //
		temp_0614 = new InstructionASTORE(3);
		// ARETURN: Type mismatch
		return temp_0614.getValue();
	L0618: //
		temp_061C = new InstructionIASTORE();
		// ARETURN: Type mismatch
		return temp_061C.getValue();
	L0620: //
		temp_0624 = new InstructionLASTORE();
		// ARETURN: Type mismatch
		return temp_0624.getValue();
	L0628: //
		temp_062C = new InstructionFASTORE();
		// ARETURN: Type mismatch
		return temp_062C.getValue();
	L0630: //
		temp_0634 = new InstructionDASTORE();
		// ARETURN: Type mismatch
		return temp_0634.getValue();
	L0638: //
		temp_063C = new InstructionAASTORE();
		// ARETURN: Type mismatch
		return temp_063C.getValue();
	L0640: //
		temp_0644 = new InstructionBASTORE();
		// ARETURN: Type mismatch
		return temp_0644.getValue();
	L0648: //
		temp_064C = new InstructionCASTORE();
		// ARETURN: Type mismatch
		return temp_064C.getValue();
	L0650: //
		temp_0654 = new InstructionSASTORE();
		// ARETURN: Type mismatch
		return temp_0654.getValue();
	L0658: //
		temp_065C = new InstructionPOP();
		// ARETURN: Type mismatch
		return temp_065C.getValue();
	L0660: //
		temp_0664 = new InstructionPOP2();
		// ARETURN: Type mismatch
		return temp_0664.getValue();
	L0668: //
		temp_066C = new InstructionDUP();
		// ARETURN: Type mismatch
		return temp_066C.getValue();
	L0670: //
		temp_0674 = new InstructionDUP_X1();
		// ARETURN: Type mismatch
		return temp_0674.getValue();
	L0678: //
		temp_067C = new InstructionDUP_X2();
		// ARETURN: Type mismatch
		return temp_067C.getValue();
	L0680: //
		temp_0684 = new InstructionDUP2();
		// ARETURN: Type mismatch
		return temp_0684.getValue();
	L0688: //
		temp_068C = new InstructionDUP2_X1();
		// ARETURN: Type mismatch
		return temp_068C.getValue();
	L0690: //
		temp_0694 = new InstructionDUP2_X2();
		// ARETURN: Type mismatch
		return temp_0694.getValue();
	L0698: //
		temp_069C = new InstructionSWAP();
		// ARETURN: Type mismatch
		return temp_069C.getValue();
	L06A0: //
		temp_06A4 = new InstructionIADD();
		// ARETURN: Type mismatch
		return temp_06A4.getValue();
	L06A8: //
		temp_06AC = new InstructionLADD();
		// ARETURN: Type mismatch
		return temp_06AC.getValue();
	L06B0: //
		temp_06B4 = new InstructionFADD();
		// ARETURN: Type mismatch
		return temp_06B4.getValue();
	L06B8: //
		temp_06BC = new InstructionDADD();
		// ARETURN: Type mismatch
		return temp_06BC.getValue();
	L06C0: //
		temp_06C4 = new InstructionISUB();
		// ARETURN: Type mismatch
		return temp_06C4.getValue();
	L06C8: //
		temp_06CC = new InstructionLSUB();
		// ARETURN: Type mismatch
		return temp_06CC.getValue();
	L06D0: //
		temp_06D4 = new InstructionFSUB();
		// ARETURN: Type mismatch
		return temp_06D4.getValue();
	L06D8: //
		temp_06DC = new InstructionDSUB();
		// ARETURN: Type mismatch
		return temp_06DC.getValue();
	L06E0: //
		temp_06E4 = new InstructionIMUL();
		// ARETURN: Type mismatch
		return temp_06E4.getValue();
	L06E8: //
		temp_06EC = new InstructionLMUL();
		// ARETURN: Type mismatch
		return temp_06EC.getValue();
	L06F0: //
		temp_06F4 = new InstructionFMUL();
		// ARETURN: Type mismatch
		return temp_06F4.getValue();
	L06F8: //
		temp_06FC = new InstructionDMUL();
		// ARETURN: Type mismatch
		return temp_06FC.getValue();
	L0700: //
		temp_0704 = new InstructionIDIV();
		// ARETURN: Type mismatch
		return temp_0704.getValue();
	L0708: //
		temp_070C = new InstructionLDIV();
		// ARETURN: Type mismatch
		return temp_070C.getValue();
	L0710: //
		temp_0714 = new InstructionFDIV();
		// ARETURN: Type mismatch
		return temp_0714.getValue();
	L0718: //
		temp_071C = new InstructionDDIV();
		// ARETURN: Type mismatch
		return temp_071C.getValue();
	L0720: //
		temp_0724 = new InstructionIREM();
		// ARETURN: Type mismatch
		return temp_0724.getValue();
	L0728: //
		temp_072C = new InstructionLREM();
		// ARETURN: Type mismatch
		return temp_072C.getValue();
	L0730: //
		temp_0734 = new InstructionFREM();
		// ARETURN: Type mismatch
		return temp_0734.getValue();
	L0738: //
		temp_073C = new InstructionDREM();
		// ARETURN: Type mismatch
		return temp_073C.getValue();
	L0740: //
		temp_0744 = new InstructionINEG();
		// ARETURN: Type mismatch
		return temp_0744.getValue();
	L0748: //
		temp_074C = new InstructionLNEG();
		// ARETURN: Type mismatch
		return temp_074C.getValue();
	L0750: //
		temp_0754 = new InstructionFNEG();
		// ARETURN: Type mismatch
		return temp_0754.getValue();
	L0758: //
		temp_075C = new InstructionDNEG();
		// ARETURN: Type mismatch
		return temp_075C.getValue();
	L0760: //
		temp_0764 = new InstructionISHL();
		// ARETURN: Type mismatch
		return temp_0764.getValue();
	L0768: //
		temp_076C = new InstructionLSHL();
		// ARETURN: Type mismatch
		return temp_076C.getValue();
	L0770: //
		temp_0774 = new InstructionISHR();
		// ARETURN: Type mismatch
		return temp_0774.getValue();
	L0778: //
		temp_077C = new InstructionLSHR();
		// ARETURN: Type mismatch
		return temp_077C.getValue();
	L0780: //
		temp_0784 = new InstructionIUSHR();
		// ARETURN: Type mismatch
		return temp_0784.getValue();
	L0788: //
		temp_078C = new InstructionLUSHR();
		// ARETURN: Type mismatch
		return temp_078C.getValue();
	L0790: //
		temp_0794 = new InstructionIAND();
		// ARETURN: Type mismatch
		return temp_0794.getValue();
	L0798: //
		temp_079C = new InstructionLAND();
		// ARETURN: Type mismatch
		return temp_079C.getValue();
	L07A0: //
		temp_07A4 = new InstructionIOR();
		// ARETURN: Type mismatch
		return temp_07A4.getValue();
	L07A8: //
		temp_07AC = new InstructionLOR();
		// ARETURN: Type mismatch
		return temp_07AC.getValue();
	L07B0: //
		temp_07B4 = new InstructionIXOR();
		// ARETURN: Type mismatch
		return temp_07B4.getValue();
	L07B8: //
		temp_07BC = new InstructionLXOR();
		// ARETURN: Type mismatch
		return temp_07BC.getValue();
	L07C0: //
		temp_07C6 = new InstructionIINC(in, false);
		// ARETURN: Type mismatch
		return temp_07C6.getValue();
	L07CA: //
		temp_07CE = new InstructionI2L();
		// ARETURN: Type mismatch
		return temp_07CE.getValue();
	L07D2: //
		temp_07D6 = new InstructionI2F();
		// ARETURN: Type mismatch
		return temp_07D6.getValue();
	L07DA: //
		temp_07DE = new InstructionI2D();
		// ARETURN: Type mismatch
		return temp_07DE.getValue();
	L07E2: //
		temp_07E6 = new InstructionL2I();
		// ARETURN: Type mismatch
		return temp_07E6.getValue();
	L07EA: //
		temp_07EE = new InstructionL2F();
		// ARETURN: Type mismatch
		return temp_07EE.getValue();
	L07F2: //
		temp_07F6 = new InstructionL2D();
		// ARETURN: Type mismatch
		return temp_07F6.getValue();
	L07FA: //
		temp_07FE = new InstructionF2I();
		// ARETURN: Type mismatch
		return temp_07FE.getValue();
	L0802: //
		temp_0806 = new InstructionF2L();
		// ARETURN: Type mismatch
		return temp_0806.getValue();
	L080A: //
		temp_080E = new InstructionF2D();
		// ARETURN: Type mismatch
		return temp_080E.getValue();
	L0812: //
		temp_0816 = new InstructionD2I();
		// ARETURN: Type mismatch
		return temp_0816.getValue();
	L081A: //
		temp_081E = new InstructionD2L();
		// ARETURN: Type mismatch
		return temp_081E.getValue();
	L0822: //
		temp_0826 = new InstructionD2F();
		// ARETURN: Type mismatch
		return temp_0826.getValue();
	L082A: //
		temp_082E = new InstructionI2B();
		// ARETURN: Type mismatch
		return temp_082E.getValue();
	L0832: //
		temp_0836 = new InstructionI2C();
		// ARETURN: Type mismatch
		return temp_0836.getValue();
	L083A: //
		temp_083E = new InstructionI2S();
		// ARETURN: Type mismatch
		return temp_083E.getValue();
	L0842: //
		temp_0846 = new InstructionLCMP();
		// ARETURN: Type mismatch
		return temp_0846.getValue();
	L084A: //
		temp_084E = new InstructionFCMPL();
		// ARETURN: Type mismatch
		return temp_084E.getValue();
	L0852: //
		temp_0856 = new InstructionFCMPG();
		// ARETURN: Type mismatch
		return temp_0856.getValue();
	L085A: //
		temp_085E = new InstructionDCMPL();
		// ARETURN: Type mismatch
		return temp_085E.getValue();
	L0862: //
		temp_0866 = new InstructionDCMPG();
		// ARETURN: Type mismatch
		return temp_0866.getValue();
	L086A: //
		temp_086F = new InstructionIFEQ(in);
		// ARETURN: Type mismatch
		return temp_086F.getValue();
	L0873: //
		temp_0878 = new InstructionIFNE(in);
		// ARETURN: Type mismatch
		return temp_0878.getValue();
	L087C: //
		temp_0881 = new InstructionIFLT(in);
		// ARETURN: Type mismatch
		return temp_0881.getValue();
	L0885: //
		temp_088A = new InstructionIFGE(in);
		// ARETURN: Type mismatch
		return temp_088A.getValue();
	L088E: //
		temp_0893 = new InstructionIFGT(in);
		// ARETURN: Type mismatch
		return temp_0893.getValue();
	L0897: //
		temp_089C = new InstructionIFLE(in);
		// ARETURN: Type mismatch
		return temp_089C.getValue();
	L08A0: //
		temp_08A5 = new InstructionIF_ICMPEQ(in);
		// ARETURN: Type mismatch
		return temp_08A5.getValue();
	L08A9: //
		temp_08AE = new InstructionIF_ICMPNE(in);
		// ARETURN: Type mismatch
		return temp_08AE.getValue();
	L08B2: //
		temp_08B7 = new InstructionIF_ICMPLT(in);
		// ARETURN: Type mismatch
		return temp_08B7.getValue();
	L08BB: //
		temp_08C0 = new InstructionIF_ICMPGE(in);
		// ARETURN: Type mismatch
		return temp_08C0.getValue();
	L08C4: //
		temp_08C9 = new InstructionIF_ICMPGT(in);
		// ARETURN: Type mismatch
		return temp_08C9.getValue();
	L08CD: //
		temp_08D2 = new InstructionIF_ICMPLE(in);
		// ARETURN: Type mismatch
		return temp_08D2.getValue();
	L08D6: //
		temp_08DB = new InstructionIF_ACMPEQ(in);
		// ARETURN: Type mismatch
		return temp_08DB.getValue();
	L08DF: //
		temp_08E4 = new InstructionIF_ACMPNE(in);
		// ARETURN: Type mismatch
		return temp_08E4.getValue();
	L08E8: //
		temp_08ED = new InstructionGOTO(in);
		// ARETURN: Type mismatch
		return temp_08ED.getValue();
	L08F1: //
		temp_08F6 = new InstructionJSR(in);
		// ARETURN: Type mismatch
		return temp_08F6.getValue();
	L08FA: //
		temp_0900 = new InstructionRET(in, false);
		// ARETURN: Type mismatch
		return temp_0900.getValue();
	L0904: //
		temp_0909 = new InstructionTABLESWITCH(in);
		// ARETURN: Type mismatch
		return temp_0909.getValue();
	L090D: //
		temp_0912 = new InstructionLOOKUPSWITCH(in);
		// ARETURN: Type mismatch
		return temp_0912.getValue();
	L0916: //
		temp_091A = new InstructionIRETURN();
		// ARETURN: Type mismatch
		return temp_091A.getValue();
	L091E: //
		temp_0922 = new InstructionLRETURN();
		// ARETURN: Type mismatch
		return temp_0922.getValue();
	L0926: //
		temp_092A = new InstructionFRETURN();
		// ARETURN: Type mismatch
		return temp_092A.getValue();
	L092E: //
		temp_0932 = new InstructionDRETURN();
		// ARETURN: Type mismatch
		return temp_0932.getValue();
	L0936: //
		temp_093A = new InstructionARETURN();
		// ARETURN: Type mismatch
		return temp_093A.getValue();
	L093E: //
		temp_0942 = new InstructionRETURN();
		// ARETURN: Type mismatch
		return temp_0942.getValue();
	L0946: //
		temp_094C = new InstructionGETSTATIC(in, cp);
		// ARETURN: Type mismatch
		return temp_094C.getValue();
	L0950: //
		temp_0956 = new InstructionPUTSTATIC(in, cp);
		// ARETURN: Type mismatch
		return temp_0956.getValue();
	L095A: //
		temp_0960 = new InstructionGETFIELD(in, cp);
		// ARETURN: Type mismatch
		return temp_0960.getValue();
	L0964: //
		temp_096A = new InstructionPUTFIELD(in, cp);
		// ARETURN: Type mismatch
		return temp_096A.getValue();
	L096E: //
		temp_0974 = new InstructionINVOKEVIRTUAL(in, cp);
		// ARETURN: Type mismatch
		return temp_0974.getValue();
	L0978: //
		temp_097E = new InstructionINVOKESPECIAL(in, cp);
		// ARETURN: Type mismatch
		return temp_097E.getValue();
	L0982: //
		temp_0988 = new InstructionINVOKESTATIC(in, cp);
		// ARETURN: Type mismatch
		return temp_0988.getValue();
	L098C: //
		temp_0992 = new InstructionINVOKEINTERFACE(in, cp);
		// ARETURN: Type mismatch
		return temp_0992.getValue();
	L0996: //
		temp_099B = new InstructionINVOKEDYNAMIC(in);
		// ARETURN: Type mismatch
		return temp_099B.getValue();
	L099F: //
		temp_09A5 = new InstructionNEW(in, cp);
		// ARETURN: Type mismatch
		return temp_09A5.getValue();
	L09A9: //
		temp_09AE = new InstructionNEWARRAY(in);
		// ARETURN: Type mismatch
		return temp_09AE.getValue();
	L09B2: //
		temp_09B8 = new InstructionANEWARRAY(in, cp);
		// ARETURN: Type mismatch
		return temp_09B8.getValue();
	L09BC: //
		temp_09C0 = new InstructionARRAYLENGTH();
		// ARETURN: Type mismatch
		return temp_09C0.getValue();
	L09C4: //
		temp_09C8 = new InstructionATHROW();
		// ARETURN: Type mismatch
		return temp_09C8.getValue();
	L09CC: //
		temp_09D2 = new InstructionCHECKCAST(in, cp);
		// ARETURN: Type mismatch
		return temp_09D2.getValue();
	L09D6: //
		temp_09DC = new InstructionINSTANCEOF(in, cp);
		// ARETURN: Type mismatch
		return temp_09DC.getValue();
	L09E0: //
		temp_09E4 = new InstructionMONITORENTER();
		// ARETURN: Type mismatch
		return temp_09E4.getValue();
	L09E8: //
		temp_09EC = new InstructionMONITOREXIT();
		// ARETURN: Type mismatch
		return temp_09EC.getValue();
	L09F0: //
		temp_09F5 = new InstructionWIDE(in);
		// ARETURN: Type mismatch
		return temp_09F5.getValue();
	L09F9: //
		temp_09FE = new InstructionMULTIANEWARRAY(in);
		// ARETURN: Type mismatch
		return temp_09FE.getValue();
	L0A02: //
		temp_0A07 = new InstructionIFNULL(in);
		// ARETURN: Type mismatch
		return temp_0A07.getValue();
	L0A0B: //
		temp_0A10 = new InstructionIFNONNULL(in);
		// ARETURN: Type mismatch
		return temp_0A10.getValue();
	L0A14: //
		temp_0A19 = new InstructionGOTO_W(in);
		// ARETURN: Type mismatch
		return temp_0A19.getValue();
	L0A1D: //
		temp_0A22 = new InstructionJSR_W(in);
		// ARETURN: Type mismatch
		return temp_0A22.getValue();
	L0A26: //
		// ARETURN: Type mismatch
		return (Instruction*)nullptr;
	}

	void Instruction::addLabel(int address, Pointer<JavaRawArray<bool>> labels)
	{
		UsageCounterMaintainer maintainer(this, true);

		return;
	}

	void Instruction::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0010;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		stream->iprintln(className_0010);
		return;
	}

	bool Instruction::fallsThrough()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 1;
	}

	int Instruction::getIndex()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -1;
	}

	int Instruction::getTargetAddress(int index)
	{
		UsageCounterMaintainer maintainer(this, true);

		Statics::__ClassInit();
		Statics::Assert(false, createString("Instruction.getTargetAddress: No jump target"));
		return -1;
	}

	int Instruction::getTargetCount()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 0;
	}

	bool Instruction::isXStore()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 0;
	}

	int Instruction::length()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 1;
	}

	void Instruction::oneLineDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->detailedDump(stream);
		return;
	}

	void Instruction::setAddress(int address)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->address = address;
		return;
	}

}
