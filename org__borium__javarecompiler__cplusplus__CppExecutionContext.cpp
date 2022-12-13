#include "stdafx.h"
#include "org__borium__javarecompiler__cplusplus__CppExecutionContext.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__io__PrintStream.h"
#include "java__lang__Character.h"
#include "java__lang__Class.h"
#include "java__lang__Integer.h"
#include "java__lang__Object.h"
#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__lang__System.h"
#include "java__util__ArrayList.h"
#include "java__util__HashMap.h"
#include "java__util__Stack.h"
#include "org__borium__javarecompiler__Recomp.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__ClassFile.h"
#include "org__borium__javarecompiler__classfile__ClassMethod.h"
#include "org__borium__javarecompiler__classfile__ClassTypeSimplifier.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeCode.h"
#include "org__borium__javarecompiler__classfile__constants__Constant.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantDouble.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantFloat.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantInteger.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantStringInfo.h"
#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"
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
#include "org__borium__javarecompiler__classfile__instruction__InstructionWithLabel.h"
#include "org__borium__javarecompiler__cplusplus__CppClass.h"
#include "org__borium__javarecompiler__cplusplus__CppMethod.h"
#include "org__borium__javarecompiler__cplusplus__JavaTypeConverter.h"
#include "org__borium__javarecompiler__cplusplus__LocalVariable.h"
#include "org__borium__javarecompiler__cplusplus__LocalVariables.h"
#include "org__borium__javarecompiler__cplusplus__TernaryOperator.h"

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::classfile::instruction;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	Pointer<Class> CppExecutionContext::__thisClassStatic;

	void CppExecutionContext::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::cplusplus::CppExecutionContext",
			org::borium::javarecompiler::classfile::ExecutionContext::__thisClassStatic);

		org::borium::javarecompiler::classfile::ExecutionContext::__ClassInit();
	}

	CppExecutionContext::CppExecutionContext(Pointer<CppMethod> cppMethod, Pointer<CppClass> cppClass, Pointer<ClassMethod> javaMethod) :
		ExecutionContext(javaMethod) //
		, codeSize(0) //
		, isStaticConstructor(false) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<Stack<Object>> temp_000A;
		Pointer<LocalVariables> temp_002B;
		Pointer<JavaTypeConverter> temp_004A;
		Pointer<StringBuilder> temp_005F;
		temp_000A = new Stack<Object>();
		this->ternaryStack = (Stack<TernaryOperator>*)temp_000A.getValue();
		this->cppClass = cppClass.getValue();
		this->cppMethod = cppMethod.getValue();
		if (javaMethod->isAbstract())
			goto L0031;
		temp_002B = new LocalVariables(javaMethod->getLocalVariableTable(), cppClass);
		this->locals = temp_002B.getValue();
	L0031: //
		this->type = javaMethod->getType().getValue();
		temp_004A = new JavaTypeConverter(this->type, javaMethod->isStatic(), this->locals);
		this->cppType = temp_004A->getCppType().getValue();
		String::__ClassInit();
		temp_005F = new StringBuilder(String::valueOf(cppClass->nameSpace.getValue()));
		this->classType = temp_005F->append(createString("::"))->append(cppClass->className)->toString().getValue();
		if (javaMethod->isAbstract())
			goto L0086;
		this->codeSize = javaMethod->getCode()->getLength();
	L0086: //
		return;
	}

	void CppExecutionContext::generate(Pointer<IndentedOutputStream> source, Pointer<Instruction> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<TernaryOperator> ternary_000E;
		Pointer<JavaArray<String>> falseExpr_0035;
		Pointer<JavaArray<String>> trueExpr_0046;
		Pointer<JavaArray<String>> condition_0057;
		Pointer<String> opcode_017B;
		Pointer<TernaryOperator> temp_000A;
		Pointer<String> temp_002B;
		Pointer<String> temp_003C;
		Pointer<String> temp_004D;
		Pointer<StringBuilder> temp_007A;
		Pointer<StringBuilder> temp_00A2;
		Pointer<StringBuilder> temp_00CA;
		Pointer<StringBuilder> temp_00F9;
		Pointer<StringBuilder> temp_0122;
		Pointer<String> local_017D;
		Pointer<InstructionNOP> temp_0E8C;
		Pointer<InstructionACONST_NULL> temp_0E98;
		Pointer<InstructionICONST> temp_0EA4;
		Pointer<InstructionLCONST> temp_0EB0;
		Pointer<InstructionFCONST> temp_0EBC;
		Pointer<InstructionDCONST> temp_0EC8;
		Pointer<InstructionBIPUSH> temp_0ED4;
		Pointer<InstructionSIPUSH> temp_0EE0;
		Pointer<InstructionLDC> temp_0EEC;
		Pointer<InstructionLDC_W> temp_0EF8;
		Pointer<InstructionLDC2_W> temp_0F04;
		Pointer<InstructionILOAD> temp_0F10;
		Pointer<InstructionLLOAD> temp_0F1C;
		Pointer<InstructionFLOAD> temp_0F28;
		Pointer<InstructionDLOAD> temp_0F34;
		Pointer<InstructionALOAD> temp_0F40;
		Pointer<InstructionIALOAD> temp_0F4C;
		Pointer<InstructionLALOAD> temp_0F58;
		Pointer<InstructionFALOAD> temp_0F64;
		Pointer<InstructionDALOAD> temp_0F70;
		Pointer<InstructionAALOAD> temp_0F7C;
		Pointer<InstructionBALOAD> temp_0F88;
		Pointer<InstructionCALOAD> temp_0F94;
		Pointer<InstructionSALOAD> temp_0FA0;
		Pointer<InstructionISTORE> temp_0FAC;
		Pointer<InstructionLSTORE> temp_0FB8;
		Pointer<InstructionFSTORE> temp_0FC4;
		Pointer<InstructionDSTORE> temp_0FD0;
		Pointer<InstructionASTORE> temp_0FDC;
		Pointer<InstructionIASTORE> temp_0FE8;
		Pointer<InstructionLASTORE> temp_0FF4;
		Pointer<InstructionFASTORE> temp_1000;
		Pointer<InstructionDASTORE> temp_100C;
		Pointer<InstructionAASTORE> temp_1018;
		Pointer<InstructionBASTORE> temp_1024;
		Pointer<InstructionCASTORE> temp_1030;
		Pointer<InstructionSASTORE> temp_103C;
		Pointer<InstructionPOP> temp_1048;
		Pointer<InstructionPOP2> temp_1054;
		Pointer<InstructionDUP> temp_1060;
		Pointer<InstructionDUP_X1> temp_106C;
		Pointer<InstructionDUP_X2> temp_1078;
		Pointer<InstructionDUP2> temp_1084;
		Pointer<InstructionDUP2_X1> temp_1090;
		Pointer<InstructionDUP2_X2> temp_109C;
		Pointer<InstructionSWAP> temp_10A8;
		Pointer<InstructionIADD> temp_10B4;
		Pointer<InstructionLADD> temp_10C0;
		Pointer<InstructionFADD> temp_10CC;
		Pointer<InstructionDADD> temp_10D8;
		Pointer<InstructionISUB> temp_10E4;
		Pointer<InstructionLSUB> temp_10F0;
		Pointer<InstructionFSUB> temp_10FC;
		Pointer<InstructionDSUB> temp_1108;
		Pointer<InstructionIMUL> temp_1114;
		Pointer<InstructionLMUL> temp_1120;
		Pointer<InstructionFMUL> temp_112C;
		Pointer<InstructionDMUL> temp_1138;
		Pointer<InstructionIDIV> temp_1144;
		Pointer<InstructionLDIV> temp_1150;
		Pointer<InstructionFDIV> temp_115C;
		Pointer<InstructionDDIV> temp_1168;
		Pointer<InstructionIREM> temp_1174;
		Pointer<InstructionLREM> temp_1180;
		Pointer<InstructionFREM> temp_118C;
		Pointer<InstructionDREM> temp_1198;
		Pointer<InstructionINEG> temp_11A4;
		Pointer<InstructionLNEG> temp_11B0;
		Pointer<InstructionFNEG> temp_11BC;
		Pointer<InstructionDNEG> temp_11C8;
		Pointer<InstructionISHL> temp_11D4;
		Pointer<InstructionLSHL> temp_11E0;
		Pointer<InstructionISHR> temp_11EC;
		Pointer<InstructionLSHR> temp_11F8;
		Pointer<InstructionIUSHR> temp_1204;
		Pointer<InstructionLUSHR> temp_1210;
		Pointer<InstructionIAND> temp_121C;
		Pointer<InstructionLAND> temp_1228;
		Pointer<InstructionIOR> temp_1234;
		Pointer<InstructionLOR> temp_1240;
		Pointer<InstructionIXOR> temp_124C;
		Pointer<InstructionLXOR> temp_1258;
		Pointer<InstructionIINC> temp_1264;
		Pointer<InstructionI2L> temp_1270;
		Pointer<InstructionI2F> temp_127C;
		Pointer<InstructionI2D> temp_1288;
		Pointer<InstructionL2I> temp_1294;
		Pointer<InstructionL2F> temp_12A0;
		Pointer<InstructionL2D> temp_12AC;
		Pointer<InstructionF2I> temp_12B8;
		Pointer<InstructionF2L> temp_12C4;
		Pointer<InstructionF2D> temp_12D0;
		Pointer<InstructionD2I> temp_12DC;
		Pointer<InstructionD2L> temp_12E8;
		Pointer<InstructionD2F> temp_12F4;
		Pointer<InstructionI2B> temp_1300;
		Pointer<InstructionI2C> temp_130C;
		Pointer<InstructionI2S> temp_1318;
		Pointer<InstructionLCMP> temp_1324;
		Pointer<InstructionFCMPL> temp_1330;
		Pointer<InstructionFCMPG> temp_133C;
		Pointer<InstructionDCMPL> temp_1348;
		Pointer<InstructionDCMPG> temp_1354;
		Pointer<InstructionIFEQ> temp_1360;
		Pointer<InstructionIFNE> temp_136C;
		Pointer<InstructionIFLT> temp_1378;
		Pointer<InstructionIFGE> temp_1384;
		Pointer<InstructionIFGT> temp_1390;
		Pointer<InstructionIFLE> temp_139C;
		Pointer<InstructionIF_ICMPEQ> temp_13A8;
		Pointer<InstructionIF_ICMPNE> temp_13B4;
		Pointer<InstructionIF_ICMPLT> temp_13C0;
		Pointer<InstructionIF_ICMPGE> temp_13CC;
		Pointer<InstructionIF_ICMPGT> temp_13D8;
		Pointer<InstructionIF_ICMPLE> temp_13E4;
		Pointer<InstructionIF_ACMPEQ> temp_13F0;
		Pointer<InstructionIF_ACMPNE> temp_13FC;
		Pointer<InstructionGOTO> temp_1408;
		Pointer<InstructionJSR> temp_1414;
		Pointer<InstructionRET> temp_1420;
		Pointer<InstructionTABLESWITCH> temp_142C;
		Pointer<InstructionLOOKUPSWITCH> temp_1438;
		Pointer<InstructionIRETURN> temp_1444;
		Pointer<InstructionLRETURN> temp_1450;
		Pointer<InstructionFRETURN> temp_145C;
		Pointer<InstructionDRETURN> temp_1468;
		Pointer<InstructionARETURN> temp_1474;
		Pointer<InstructionRETURN> temp_1480;
		Pointer<InstructionGETSTATIC> temp_148C;
		Pointer<InstructionPUTSTATIC> temp_1498;
		Pointer<InstructionGETFIELD> temp_14A4;
		Pointer<InstructionPUTFIELD> temp_14B0;
		Pointer<InstructionINVOKEVIRTUAL> temp_14BC;
		Pointer<InstructionINVOKESPECIAL> temp_14C8;
		Pointer<InstructionINVOKESTATIC> temp_14D4;
		Pointer<InstructionINVOKEINTERFACE> temp_14E0;
		Pointer<InstructionINVOKEDYNAMIC> temp_14EC;
		Pointer<InstructionNEW> temp_14F8;
		Pointer<InstructionNEWARRAY> temp_1504;
		Pointer<InstructionANEWARRAY> temp_1510;
		Pointer<InstructionARRAYLENGTH> temp_151C;
		Pointer<InstructionATHROW> temp_1528;
		Pointer<InstructionCHECKCAST> temp_1534;
		Pointer<InstructionINSTANCEOF> temp_1540;
		Pointer<InstructionMONITORENTER> temp_154C;
		Pointer<InstructionMONITOREXIT> temp_1558;
		Pointer<InstructionWIDE> temp_1564;
		Pointer<InstructionMULTIANEWARRAY> temp_1570;
		Pointer<InstructionIFNULL> temp_157C;
		Pointer<InstructionIFNONNULL> temp_1588;
		Pointer<InstructionGOTO_W> temp_1594;
		Pointer<InstructionJSR_W> temp_15A0;
		Pointer<StringBuilder> temp_15B3;
		goto L0164;
	L0003: //
		temp_000A = (TernaryOperator*)((this->ternaryStack->firstElement()).getValue());
		temp_000A->checkCast(TernaryOperator::__thisClassStatic);
		ternary_000E = temp_000A;
		if ((ternary_000E->endAddress) == (instruction->address))
			goto L001C;
		goto L016E;
	L001C: //
		this->ternaryStack->pop();
		temp_002B = (String*)((this->stack->pop()).getValue());
		temp_002B->checkCast(String::__thisClassStatic);
		falseExpr_0035 = (JavaArray<String>*)(temp_002B->split(createString("[\t]")).getValue());
		temp_003C = (String*)((this->stack->pop()).getValue());
		temp_003C->checkCast(String::__thisClassStatic);
		trueExpr_0046 = (JavaArray<String>*)(temp_003C->split(createString("[\t]")).getValue());
		temp_004D = (String*)((this->stack->pop()).getValue());
		temp_004D->checkCast(String::__thisClassStatic);
		condition_0057 = (JavaArray<String>*)(temp_004D->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(condition_0057->get(0)->equals(createString("bool")), createString("Ternary: Boolean condition expected"));
		if (!(trueExpr_0046->get(1)->startsWith(createString("\""))))
			goto L008D;
		temp_007A = new StringBuilder(createString("((Pointer<String>) new String("));
		trueExpr_0046->assign(1, temp_007A->append(trueExpr_0046->get(1))->append(createString("))"))->toString());
	L008D: //
		if (!(falseExpr_0035->get(1)->startsWith(createString("\""))))
			goto L00B5;
		temp_00A2 = new StringBuilder(createString("((Pointer<String>) new String("));
		falseExpr_0035->assign(1, temp_00A2->append(falseExpr_0035->get(1))->append(createString("))"))->toString());
	L00B5: //
		if (!(trueExpr_0046->get(1)->equals(createString("nullptr"))))
			goto L00E4;
		temp_00CA = new StringBuilder(createString("("));
		trueExpr_0046->assign(1, temp_00CA->append(falseExpr_0035->get(0))->append(createString("*)"))->append(trueExpr_0046->get(1))->toString());
	L00E4: //
		if (!(falseExpr_0035->get(0)->equals(createString("nullptr"))))
			goto L0113;
		temp_00F9 = new StringBuilder(createString("("));
		falseExpr_0035->assign(1, temp_00F9->append(trueExpr_0046->get(0))->append(createString("*)"))->append(falseExpr_0035->get(1))->toString());
	L0113: //
		String::__ClassInit();
		temp_0122 = new StringBuilder(String::valueOf(trueExpr_0046->get(0).getValue()));
		this->stack->push(temp_0122->append(createString("\t"))->append(createString("("))->append(condition_0057->get(1))->append(createString(" ? "))->append(createString("("))->append(trueExpr_0046->get(1))->append(createString(") : "))->append(createString("("))->append(falseExpr_0035->get(1))->append(createString("))"))->toString().getValue());
	L0164: //
		if ((this->ternaryStack->size()) > 0)
			goto L0003;
	L016E: //
		opcode_017B = instruction->getClass()->getSimpleName()->substring(11);
		local_017D = opcode_017B;
		switch (opcode_017B->hashCode())
		{
		case (int)0x804979FE:
			goto L064C;
		case (int)0x8067049A:
			goto L0659;
		case (int)0x8090F024:
			goto L0666;
		case (int)0x80CBBE64:
			goto L0673;
		case (int)0x80D9BCB9:
			goto L0680;
		case (int)0x814AC618:
			goto L068D;
		case (int)0x856803DB:
			goto L069A;
		case (int)0x85858E77:
			goto L06A7;
		case (int)0x858DC9DF:
			goto L06B4;
		case (int)0x86694FF5:
			goto L06C1;
		case (int)0x894AE6A9:
			goto L06CE;
		case (int)0x8FE13130:
			goto L06DB;
		case (int)0x9159F034:
			goto L06E8;
		case (int)0x91CC9670:
			goto L06F5;
		case (int)0x9A236F4B:
			goto L0702;
		case (int)0x9A493733:
			goto L070F;
		case (int)0x9D08EE74:
			goto L071C;
		case (int)0xA2B32C65:
			goto L0729;
		case (int)0xA2B32C66:
			goto L0736;
		case (int)0xA487C0E6:
			goto L0743;
		case (int)0xA4D52764:
			goto L0751;
		case (int)0xA58816B9:
			goto L075F;
		case (int)0xA64BC52E:
			goto L076D;
		case (int)0xBDE0AC27:
			goto L077B;
		case (int)0xC112CA1D:
			goto L0789;
		case (int)0xC3454613:
			goto L0797;
		case (int)0xC345471E:
			goto L07A5;
		case (int)0xC6CAF462:
			goto L07B3;
		case (int)0xD0EC0B0B:
			goto L07C1;
		case (int)0xD0EC0B3D:
			goto L07CF;
		case (int)0xD0EC0B4C:
			goto L07DD;
		case (int)0xD0EC0BD8:
			goto L07EB;
		case (int)0xD0EC0BE7:
			goto L07F9;
		case (int)0xD0EC0C16:
			goto L0807;
		case (int)0xD55B5A5F:
			goto L0815;
		case (int)0xDC29BCA7:
			goto L0823;
		case (int)0xDE81CD58:
			goto L0831;
		case (int)0xE05FAC04:
			goto L083F;
		case (int)0xE2190CA1:
			goto L084D;
		case (int)0xE5CD9D21:
			goto L085B;
		case (int)0xEA9834E6:
			goto L0869;
		case (int)0xF1B379BE:
			goto L0877;
		case (int)0xFE563CB1:
			goto L0885;
		case (int)0x00010598:
			goto L0893;
		case (int)0x0001059B:
			goto L08A1;
		case (int)0x0001059E:
			goto L08AF;
		case (int)0x000109DF:
			goto L08BD;
		case (int)0x00010D18:
			goto L08CB;
		case (int)0x00010D1D:
			goto L08D9;
		case (int)0x00010D20:
			goto L08E7;
		case (int)0x00011859:
			goto L08F5;
		case (int)0x0001185A:
			goto L0903;
		case (int)0x0001185B:
			goto L0911;
		case (int)0x0001185D:
			goto L091F;
		case (int)0x00011863:
			goto L092D;
		case (int)0x0001186A:
			goto L093B;
		case (int)0x00011BEC:
			goto L0949;
		case (int)0x00012029:
			goto L0957;
		case (int)0x0001239E:
			goto L0965;
		case (int)0x000123A0:
			goto L0973;
		case (int)0x000123A3:
			goto L0981;
		case (int)0x000125CB:
			goto L098F;
		case (int)0x0001272F:
			goto L099D;
		case (int)0x00012D80:
			goto L09AB;
		case (int)0x00012EAF:
			goto L09B9;
		case (int)0x00013631:
			goto L09C7;
		case (int)0x00013C81:
			goto L09D5;
		case (int)0x001FE5BD:
			goto L09E3;
		case (int)0x001FF1AD:
			goto L09F1;
		case (int)0x002014E0:
			goto L09FF;
		case (int)0x002016AC:
			goto L0A0D;
		case (int)0x002025B6:
			goto L0A1B;
		case (int)0x00202B5C:
			goto L0A29;
		case (int)0x00203233:
			goto L0A37;
		case (int)0x0020CE7B:
			goto L0A45;
		case (int)0x0020DA6B:
			goto L0A53;
		case (int)0x0020FD9E:
			goto L0A61;
		case (int)0x0020FF6A:
			goto L0A6F;
		case (int)0x00210E74:
			goto L0A7D;
		case (int)0x0021141A:
			goto L0A8B;
		case (int)0x00217963:
			goto L0A99;
		case (int)0x00222B98:
			goto L0AA7;
		case (int)0x00222CCE:
			goto L0AB5;
		case (int)0x00223788:
			goto L0AC3;
		case (int)0x00223E89:
			goto L0AD1;
		case (int)0x00223EBB:
			goto L0ADF;
		case (int)0x00223ECA:
			goto L0AED;
		case (int)0x00223F56:
			goto L0AFB;
		case (int)0x00223F65:
			goto L0B09;
		case (int)0x00223F94:
			goto L0B17;
		case (int)0x00224AD5:
			goto L0B25;
		case (int)0x00225ABB:
			goto L0B33;
		case (int)0x00225C87:
			goto L0B41;
		case (int)0x00226B91:
			goto L0B4F;
		case (int)0x00226FAE:
			goto L0B5D;
		case (int)0x00226FB4:
			goto L0B6B;
		case (int)0x00227137:
			goto L0B79;
		case (int)0x00228352:
			goto L0B87;
		case (int)0x002388B5:
			goto L0B95;
		case (int)0x002389EB:
			goto L0BA3;
		case (int)0x0023915A:
			goto L0BB1;
		case (int)0x002394A5:
			goto L0BBF;
		case (int)0x0023B7D8:
			goto L0BCD;
		case (int)0x0023B9A4:
			goto L0BDB;
		case (int)0x0023C8AE:
			goto L0BE9;
		case (int)0x0023CCCB:
			goto L0BF7;
		case (int)0x0023CCD1:
			goto L0C05;
		case (int)0x0023CE54:
			goto L0C13;
		case (int)0x0023E06F:
			goto L0C21;
		case (int)0x00259021:
			goto L0C2F;
		case (int)0x00270993:
			goto L0C3D;
		case (int)0x0028A6D3:
			goto L0C4B;
		case (int)0x03B7B4A7:
			goto L0C59;
		case (int)0x03DDDE25:
			goto L0C67;
		case (int)0x03DDDE2A:
			goto L0C75;
		case (int)0x03E1FB2A:
			goto L0C83;
		case (int)0x03FA0D27:
			goto L0C91;
		case (int)0x03FA0D2C:
			goto L0C9F;
		case (int)0x03FE2A2C:
			goto L0CAD;
		case (int)0x042870AF:
			goto L0CBB;
		case (int)0x042C97F1:
			goto L0CC9;
		case (int)0x0439C5C1:
			goto L0CD7;
		case (int)0x044EEAE3:
			goto L0CE5;
		case (int)0x0452B732:
			goto L0CF3;
		case (int)0x0456DE74:
			goto L0D01;
		case (int)0x06D564F6:
			goto L0D0F;
		case (int)0x0C981524:
			goto L0D1D;
		case (int)0x1429BB01:
			goto L0D2B;
		case (int)0x16FF47E2:
			goto L0D39;
		case (int)0x2639EBFA:
			goto L0D47;
		case (int)0x27FD986C:
			goto L0D55;
		case (int)0x2BD44BA1:
			goto L0D63;
		case (int)0x443AC87C:
			goto L0D71;
		case (int)0x4BE58323:
			goto L0D7F;
		case (int)0x52ADBD2C:
			goto L0D8D;
		case (int)0x587AB9F7:
			goto L0D9B;
		case (int)0x72A2B506:
			goto L0DA9;
		case (int)0x73A40120:
			goto L0DB7;
		case (int)0x73ACAF25:
			goto L0DC5;
		case (int)0x74578DA5:
			goto L0DD3;
		case (int)0x74CA33E1:
			goto L0DE1;
		case (int)0x760C6644:
			goto L0DEF;
		case (int)0x77C13EE3:
			goto L0DFD;
		case (int)0x77DEC97F:
			goto L0E0B;
		case (int)0x78C28AFD:
			goto L0E19;
		case (int)0x78DD2539:
			goto L0E27;
		case (int)0x78DD253A:
			goto L0E35;
		case (int)0x794D7B73:
			goto L0E43;
		case (int)0x7B2AF021:
			goto L0E51;
		case (int)0x7B487ABD:
			goto L0E5F;
		case (int)0x7C2C3C3B:
			goto L0E6D;
		case (int)0x7DA8B87B:
			goto L0E7B;
		default:
			goto L15A9;
		}
	L064C: //
		if (local_017D->equals(createString("IALOAD")))
			goto L0F49;
		goto L15A9;
	L0659: //
		if (local_017D->equals(createString("ICONST")))
			goto L0EA1;
		goto L15A9;
	L0666: //
		if (local_017D->equals(createString("IFNULL")))
			goto L1579;
		goto L15A9;
	L0673: //
		if (local_017D->equals(createString("DASTORE")))
			goto L1009;
		goto L15A9;
	L0680: //
		if (local_017D->equals(createString("NEWARRAY")))
			goto L1501;
		goto L15A9;
	L068D: //
		if (local_017D->equals(createString("ISTORE")))
			goto L0FA9;
		goto L15A9;
	L069A: //
		if (local_017D->equals(createString("LALOAD")))
			goto L0F55;
		goto L15A9;
	L06A7: //
		if (local_017D->equals(createString("LCONST")))
			goto L0EAD;
		goto L15A9;
	L06B4: //
		if (local_017D->equals(createString("LDC2_W")))
			goto L0F01;
		goto L15A9;
	L06C1: //
		if (local_017D->equals(createString("LSTORE")))
			goto L0FB5;
		goto L15A9;
	L06CE: //
		if (local_017D->equals(createString("IASTORE")))
			goto L0FE5;
		goto L15A9;
	L06DB: //
		if (local_017D->equals(createString("RETURN")))
			goto L147D;
		goto L15A9;
	L06E8: //
		if (local_017D->equals(createString("SALOAD")))
			goto L0F9D;
		goto L15A9;
	L06F5: //
		if (local_017D->equals(createString("SIPUSH")))
			goto L0EDD;
		goto L15A9;
	L0702: //
		if (local_017D->equals(createString("PUTFIELD")))
			goto L14AD;
		goto L15A9;
	L070F: //
		if (local_017D->equals(createString("SASTORE")))
			goto L1039;
		goto L15A9;
	L071C: //
		if (local_017D->equals(createString("DRETURN")))
			goto L1465;
		goto L15A9;
	L0729: //
		if (local_017D->equals(createString("DUP2_X1")))
			goto L108D;
		goto L15A9;
	L0736: //
		if (local_017D->equals(createString("DUP2_X2")))
			goto L1099;
		goto L15A9;
	L0743: //
		if (local_017D->equals(createString("INVOKESTATIC")))
			goto L14D1;
		goto L15A9;
	L0751: //
		if (local_017D->equals(createString("GETFIELD")))
			goto L14A1;
		goto L15A9;
	L075F: //
		if (local_017D->equals(createString("IRETURN")))
			goto L1441;
		goto L15A9;
	L076D: //
		if (local_017D->equals(createString("LOOKUPSWITCH")))
			goto L1435;
		goto L15A9;
	L077B: //
		if (local_017D->equals(createString("CHECKCAST")))
			goto L1531;
		goto L15A9;
	L0789: //
		if (local_017D->equals(createString("PUTSTATIC")))
			goto L1495;
		goto L15A9;
	L0797: //
		if (local_017D->equals(createString("IF_ACMPEQ")))
			goto L13ED;
		goto L15A9;
	L07A5: //
		if (local_017D->equals(createString("IF_ACMPNE")))
			goto L13F9;
		goto L15A9;
	L07B3: //
		if (local_017D->equals(createString("TABLESWITCH")))
			goto L1429;
		goto L15A9;
	L07C1: //
		if (local_017D->equals(createString("IF_ICMPEQ")))
			goto L13A5;
		goto L15A9;
	L07CF: //
		if (local_017D->equals(createString("IF_ICMPGE")))
			goto L13C9;
		goto L15A9;
	L07DD: //
		if (local_017D->equals(createString("IF_ICMPGT")))
			goto L13D5;
		goto L15A9;
	L07EB: //
		if (local_017D->equals(createString("IF_ICMPLE")))
			goto L13E1;
		goto L15A9;
	L07F9: //
		if (local_017D->equals(createString("IF_ICMPLT")))
			goto L13BD;
		goto L15A9;
	L0807: //
		if (local_017D->equals(createString("IF_ICMPNE")))
			goto L13B1;
		goto L15A9;
	L0815: //
		if (local_017D->equals(createString("ARRAYLENGTH")))
			goto L1519;
		goto L15A9;
	L0823: //
		if (local_017D->equals(createString("INVOKEDYNAMIC")))
			goto L14E9;
		goto L15A9;
	L0831: //
		if (local_017D->equals(createString("MONITOREXIT")))
			goto L1555;
		goto L15A9;
	L083F: //
		if (local_017D->equals(createString("ACONST_NULL")))
			goto L0E95;
		goto L15A9;
	L084D: //
		if (local_017D->equals(createString("AASTORE")))
			goto L1015;
		goto L15A9;
	L085B: //
		if (local_017D->equals(createString("INVOKESPECIAL")))
			goto L14C5;
		goto L15A9;
	L0869: //
		if (local_017D->equals(createString("FASTORE")))
			goto L0FFD;
		goto L15A9;
	L0877: //
		if (local_017D->equals(createString("MONITORENTER")))
			goto L1549;
		goto L15A9;
	L0885: //
		if (local_017D->equals(createString("ARETURN")))
			goto L1471;
		goto L15A9;
	L0893: //
		if (local_017D->equals(createString("D2F")))
			goto L12F1;
		goto L15A9;
	L08A1: //
		if (local_017D->equals(createString("D2I")))
			goto L12D9;
		goto L15A9;
	L08AF: //
		if (local_017D->equals(createString("D2L")))
			goto L12E5;
		goto L15A9;
	L08BD: //
		if (local_017D->equals(createString("DUP")))
			goto L105D;
		goto L15A9;
	L08CB: //
		if (local_017D->equals(createString("F2D")))
			goto L12CD;
		goto L15A9;
	L08D9: //
		if (local_017D->equals(createString("F2I")))
			goto L12B5;
		goto L15A9;
	L08E7: //
		if (local_017D->equals(createString("F2L")))
			goto L12C1;
		goto L15A9;
	L08F5: //
		if (local_017D->equals(createString("I2B")))
			goto L12FD;
		goto L15A9;
	L0903: //
		if (local_017D->equals(createString("I2C")))
			goto L1309;
		goto L15A9;
	L0911: //
		if (local_017D->equals(createString("I2D")))
			goto L1285;
		goto L15A9;
	L091F: //
		if (local_017D->equals(createString("I2F")))
			goto L1279;
		goto L15A9;
	L092D: //
		if (local_017D->equals(createString("I2L")))
			goto L126D;
		goto L15A9;
	L093B: //
		if (local_017D->equals(createString("I2S")))
			goto L1315;
		goto L15A9;
	L0949: //
		if (local_017D->equals(createString("IOR")))
			goto L1231;
		goto L15A9;
	L0957: //
		if (local_017D->equals(createString("JSR")))
			goto L1411;
		goto L15A9;
	L0965: //
		if (local_017D->equals(createString("L2D")))
			goto L12A9;
		goto L15A9;
	L0973: //
		if (local_017D->equals(createString("L2F")))
			goto L129D;
		goto L15A9;
	L0981: //
		if (local_017D->equals(createString("L2I")))
			goto L1291;
		goto L15A9;
	L098F: //
		if (local_017D->equals(createString("LDC")))
			goto L0EE9;
		goto L15A9;
	L099D: //
		if (local_017D->equals(createString("LOR")))
			goto L123D;
		goto L15A9;
	L09AB: //
		if (local_017D->equals(createString("NEW")))
			goto L14F5;
		goto L15A9;
	L09B9: //
		if (local_017D->equals(createString("NOP")))
			goto L0E89;
		goto L15A9;
	L09C7: //
		if (local_017D->equals(createString("POP")))
			goto L1045;
		goto L15A9;
	L09D5: //
		if (local_017D->equals(createString("RET")))
			goto L141D;
		goto L15A9;
	L09E3: //
		if (local_017D->equals(createString("DADD")))
			goto L10D5;
		goto L15A9;
	L09F1: //
		if (local_017D->equals(createString("DDIV")))
			goto L1165;
		goto L15A9;
	L09FF: //
		if (local_017D->equals(createString("DMUL")))
			goto L1135;
		goto L15A9;
	L0A0D: //
		if (local_017D->equals(createString("DNEG")))
			goto L11C5;
		goto L15A9;
	L0A1B: //
		if (local_017D->equals(createString("DREM")))
			goto L1195;
		goto L15A9;
	L0A29: //
		if (local_017D->equals(createString("DSUB")))
			goto L1105;
		goto L15A9;
	L0A37: //
		if (local_017D->equals(createString("DUP2")))
			goto L1081;
		goto L15A9;
	L0A45: //
		if (local_017D->equals(createString("FADD")))
			goto L10C9;
		goto L15A9;
	L0A53: //
		if (local_017D->equals(createString("FDIV")))
			goto L1159;
		goto L15A9;
	L0A61: //
		if (local_017D->equals(createString("FMUL")))
			goto L1129;
		goto L15A9;
	L0A6F: //
		if (local_017D->equals(createString("FNEG")))
			goto L11B9;
		goto L15A9;
	L0A7D: //
		if (local_017D->equals(createString("FREM")))
			goto L1189;
		goto L15A9;
	L0A8B: //
		if (local_017D->equals(createString("FSUB")))
			goto L10F9;
		goto L15A9;
	L0A99: //
		if (local_017D->equals(createString("GOTO")))
			goto L1405;
		goto L15A9;
	L0AA7: //
		if (local_017D->equals(createString("IADD")))
			goto L10B1;
		goto L15A9;
	L0AB5: //
		if (local_017D->equals(createString("IAND")))
			goto L1219;
		goto L15A9;
	L0AC3: //
		if (local_017D->equals(createString("IDIV")))
			goto L1141;
		goto L15A9;
	L0AD1: //
		if (local_017D->equals(createString("IFEQ")))
			goto L135D;
		goto L15A9;
	L0ADF: //
		if (local_017D->equals(createString("IFGE")))
			goto L1381;
		goto L15A9;
	L0AED: //
		if (local_017D->equals(createString("IFGT")))
			goto L138D;
		goto L15A9;
	L0AFB: //
		if (local_017D->equals(createString("IFLE")))
			goto L1399;
		goto L15A9;
	L0B09: //
		if (local_017D->equals(createString("IFLT")))
			goto L1375;
		goto L15A9;
	L0B17: //
		if (local_017D->equals(createString("IFNE")))
			goto L1369;
		goto L15A9;
	L0B25: //
		if (local_017D->equals(createString("IINC")))
			goto L1261;
		goto L15A9;
	L0B33: //
		if (local_017D->equals(createString("IMUL")))
			goto L1111;
		goto L15A9;
	L0B41: //
		if (local_017D->equals(createString("INEG")))
			goto L11A1;
		goto L15A9;
	L0B4F: //
		if (local_017D->equals(createString("IREM")))
			goto L1171;
		goto L15A9;
	L0B5D: //
		if (local_017D->equals(createString("ISHL")))
			goto L11D1;
		goto L15A9;
	L0B6B: //
		if (local_017D->equals(createString("ISHR")))
			goto L11E9;
		goto L15A9;
	L0B79: //
		if (local_017D->equals(createString("ISUB")))
			goto L10E1;
		goto L15A9;
	L0B87: //
		if (local_017D->equals(createString("IXOR")))
			goto L1249;
		goto L15A9;
	L0B95: //
		if (local_017D->equals(createString("LADD")))
			goto L10BD;
		goto L15A9;
	L0BA3: //
		if (local_017D->equals(createString("LAND")))
			goto L1225;
		goto L15A9;
	L0BB1: //
		if (local_017D->equals(createString("LCMP")))
			goto L1321;
		goto L15A9;
	L0BBF: //
		if (local_017D->equals(createString("LDIV")))
			goto L114D;
		goto L15A9;
	L0BCD: //
		if (local_017D->equals(createString("LMUL")))
			goto L111D;
		goto L15A9;
	L0BDB: //
		if (local_017D->equals(createString("LNEG")))
			goto L11AD;
		goto L15A9;
	L0BE9: //
		if (local_017D->equals(createString("LREM")))
			goto L117D;
		goto L15A9;
	L0BF7: //
		if (local_017D->equals(createString("LSHL")))
			goto L11DD;
		goto L15A9;
	L0C05: //
		if (local_017D->equals(createString("LSHR")))
			goto L11F5;
		goto L15A9;
	L0C13: //
		if (local_017D->equals(createString("LSUB")))
			goto L10ED;
		goto L15A9;
	L0C21: //
		if (local_017D->equals(createString("LXOR")))
			goto L1255;
		goto L15A9;
	L0C2F: //
		if (local_017D->equals(createString("POP2")))
			goto L1051;
		goto L15A9;
	L0C3D: //
		if (local_017D->equals(createString("SWAP")))
			goto L10A5;
		goto L15A9;
	L0C4B: //
		if (local_017D->equals(createString("WIDE")))
			goto L1561;
		goto L15A9;
	L0C59: //
		if (local_017D->equals(createString("ALOAD")))
			goto L0F3D;
		goto L15A9;
	L0C67: //
		if (local_017D->equals(createString("DCMPG")))
			goto L1351;
		goto L15A9;
	L0C75: //
		if (local_017D->equals(createString("DCMPL")))
			goto L1345;
		goto L15A9;
	L0C83: //
		if (local_017D->equals(createString("DLOAD")))
			goto L0F31;
		goto L15A9;
	L0C91: //
		if (local_017D->equals(createString("FCMPG")))
			goto L1339;
		goto L15A9;
	L0C9F: //
		if (local_017D->equals(createString("FCMPL")))
			goto L132D;
		goto L15A9;
	L0CAD: //
		if (local_017D->equals(createString("FLOAD")))
			goto L0F25;
		goto L15A9;
	L0CBB: //
		if (local_017D->equals(createString("ILOAD")))
			goto L0F0D;
		goto L15A9;
	L0CC9: //
		if (local_017D->equals(createString("IUSHR")))
			goto L1201;
		goto L15A9;
	L0CD7: //
		if (local_017D->equals(createString("JSR_W")))
			goto L159D;
		goto L15A9;
	L0CE5: //
		if (local_017D->equals(createString("LDC_W")))
			goto L0EF5;
		goto L15A9;
	L0CF3: //
		if (local_017D->equals(createString("LLOAD")))
			goto L0F19;
		goto L15A9;
	L0D01: //
		if (local_017D->equals(createString("LUSHR")))
			goto L120D;
		goto L15A9;
	L0D0F: //
		if (local_017D->equals(createString("FRETURN")))
			goto L1459;
		goto L15A9;
	L0D1D: //
		if (local_017D->equals(createString("GETSTATIC")))
			goto L1489;
		goto L15A9;
	L0D2B: //
		if (local_017D->equals(createString("MULTIANEWARRAY")))
			goto L156D;
		goto L15A9;
	L0D39: //
		if (local_017D->equals(createString("BASTORE")))
			goto L1021;
		goto L15A9;
	L0D47: //
		if (local_017D->equals(createString("ANEWARRAY")))
			goto L150D;
		goto L15A9;
	L0D55: //
		if (local_017D->equals(createString("LASTORE")))
			goto L0FF1;
		goto L15A9;
	L0D63: //
		if (local_017D->equals(createString("INVOKEINTERFACE")))
			goto L14DD;
		goto L15A9;
	L0D71: //
		if (local_017D->equals(createString("LRETURN")))
			goto L144D;
		goto L15A9;
	L0D7F: //
		if (local_017D->equals(createString("CASTORE")))
			goto L102D;
		goto L15A9;
	L0D8D: //
		if (local_017D->equals(createString("INSTANCEOF")))
			goto L153D;
		goto L15A9;
	L0D9B: //
		if (local_017D->equals(createString("IFNONNULL")))
			goto L1585;
		goto L15A9;
	L0DA9: //
		if (local_017D->equals(createString("AALOAD")))
			goto L0F79;
		goto L15A9;
	L0DB7: //
		if (local_017D->equals(createString("ASTORE")))
			goto L0FD9;
		goto L15A9;
	L0DC5: //
		if (local_017D->equals(createString("ATHROW")))
			goto L1525;
		goto L15A9;
	L0DD3: //
		if (local_017D->equals(createString("BALOAD")))
			goto L0F85;
		goto L15A9;
	L0DE1: //
		if (local_017D->equals(createString("BIPUSH")))
			goto L0ED1;
		goto L15A9;
	L0DEF: //
		if (local_017D->equals(createString("CALOAD")))
			goto L0F91;
		goto L15A9;
	L0DFD: //
		if (local_017D->equals(createString("DALOAD")))
			goto L0F6D;
		goto L15A9;
	L0E0B: //
		if (local_017D->equals(createString("DCONST")))
			goto L0EC5;
		goto L15A9;
	L0E19: //
		if (local_017D->equals(createString("DSTORE")))
			goto L0FCD;
		goto L15A9;
	L0E27: //
		if (local_017D->equals(createString("DUP_X1")))
			goto L1069;
		goto L15A9;
	L0E35: //
		if (local_017D->equals(createString("DUP_X2")))
			goto L1075;
		goto L15A9;
	L0E43: //
		if (local_017D->equals(createString("INVOKEVIRTUAL")))
			goto L14B9;
		goto L15A9;
	L0E51: //
		if (local_017D->equals(createString("FALOAD")))
			goto L0F61;
		goto L15A9;
	L0E5F: //
		if (local_017D->equals(createString("FCONST")))
			goto L0EB9;
		goto L15A9;
	L0E6D: //
		if (local_017D->equals(createString("FSTORE")))
			goto L0FC1;
		goto L15A9;
	L0E7B: //
		if (local_017D->equals(createString("GOTO_W")))
			goto L1591;
		goto L15A9;
	L0E89: //
		temp_0E8C = (InstructionNOP*)((instruction).getValue());
		temp_0E8C->checkCast(InstructionNOP::__thisClassStatic);
		this->generateNOP(source, temp_0E8C);
		goto L15C6;
	L0E95: //
		temp_0E98 = (InstructionACONST_NULL*)((instruction).getValue());
		temp_0E98->checkCast(InstructionACONST_NULL::__thisClassStatic);
		this->generateACONST_NULL(source, temp_0E98);
		goto L15C6;
	L0EA1: //
		temp_0EA4 = (InstructionICONST*)((instruction).getValue());
		temp_0EA4->checkCast(InstructionICONST::__thisClassStatic);
		this->generateICONST(source, temp_0EA4);
		goto L15C6;
	L0EAD: //
		temp_0EB0 = (InstructionLCONST*)((instruction).getValue());
		temp_0EB0->checkCast(InstructionLCONST::__thisClassStatic);
		this->generateLCONST(source, temp_0EB0);
		goto L15C6;
	L0EB9: //
		temp_0EBC = (InstructionFCONST*)((instruction).getValue());
		temp_0EBC->checkCast(InstructionFCONST::__thisClassStatic);
		this->generateFCONST(source, temp_0EBC);
		goto L15C6;
	L0EC5: //
		temp_0EC8 = (InstructionDCONST*)((instruction).getValue());
		temp_0EC8->checkCast(InstructionDCONST::__thisClassStatic);
		this->generateDCONST(source, temp_0EC8);
		goto L15C6;
	L0ED1: //
		temp_0ED4 = (InstructionBIPUSH*)((instruction).getValue());
		temp_0ED4->checkCast(InstructionBIPUSH::__thisClassStatic);
		this->generateBIPUSH(source, temp_0ED4);
		goto L15C6;
	L0EDD: //
		temp_0EE0 = (InstructionSIPUSH*)((instruction).getValue());
		temp_0EE0->checkCast(InstructionSIPUSH::__thisClassStatic);
		this->generateSIPUSH(source, temp_0EE0);
		goto L15C6;
	L0EE9: //
		temp_0EEC = (InstructionLDC*)((instruction).getValue());
		temp_0EEC->checkCast(InstructionLDC::__thisClassStatic);
		this->generateLDC(source, temp_0EEC);
		goto L15C6;
	L0EF5: //
		temp_0EF8 = (InstructionLDC_W*)((instruction).getValue());
		temp_0EF8->checkCast(InstructionLDC_W::__thisClassStatic);
		this->generateLDC_W(source, temp_0EF8);
		goto L15C6;
	L0F01: //
		temp_0F04 = (InstructionLDC2_W*)((instruction).getValue());
		temp_0F04->checkCast(InstructionLDC2_W::__thisClassStatic);
		this->generateLDC2_W(source, temp_0F04);
		goto L15C6;
	L0F0D: //
		temp_0F10 = (InstructionILOAD*)((instruction).getValue());
		temp_0F10->checkCast(InstructionILOAD::__thisClassStatic);
		this->generateILOAD(source, temp_0F10);
		goto L15C6;
	L0F19: //
		temp_0F1C = (InstructionLLOAD*)((instruction).getValue());
		temp_0F1C->checkCast(InstructionLLOAD::__thisClassStatic);
		this->generateLLOAD(source, temp_0F1C);
		goto L15C6;
	L0F25: //
		temp_0F28 = (InstructionFLOAD*)((instruction).getValue());
		temp_0F28->checkCast(InstructionFLOAD::__thisClassStatic);
		this->generateFLOAD(source, temp_0F28);
		goto L15C6;
	L0F31: //
		temp_0F34 = (InstructionDLOAD*)((instruction).getValue());
		temp_0F34->checkCast(InstructionDLOAD::__thisClassStatic);
		this->generateDLOAD(source, temp_0F34);
		goto L15C6;
	L0F3D: //
		temp_0F40 = (InstructionALOAD*)((instruction).getValue());
		temp_0F40->checkCast(InstructionALOAD::__thisClassStatic);
		this->generateALOAD(source, temp_0F40);
		goto L15C6;
	L0F49: //
		temp_0F4C = (InstructionIALOAD*)((instruction).getValue());
		temp_0F4C->checkCast(InstructionIALOAD::__thisClassStatic);
		this->generateIALOAD(source, temp_0F4C);
		goto L15C6;
	L0F55: //
		temp_0F58 = (InstructionLALOAD*)((instruction).getValue());
		temp_0F58->checkCast(InstructionLALOAD::__thisClassStatic);
		this->generateLALOAD(source, temp_0F58);
		goto L15C6;
	L0F61: //
		temp_0F64 = (InstructionFALOAD*)((instruction).getValue());
		temp_0F64->checkCast(InstructionFALOAD::__thisClassStatic);
		this->generateFALOAD(source, temp_0F64);
		goto L15C6;
	L0F6D: //
		temp_0F70 = (InstructionDALOAD*)((instruction).getValue());
		temp_0F70->checkCast(InstructionDALOAD::__thisClassStatic);
		this->generateDALOAD(source, temp_0F70);
		goto L15C6;
	L0F79: //
		temp_0F7C = (InstructionAALOAD*)((instruction).getValue());
		temp_0F7C->checkCast(InstructionAALOAD::__thisClassStatic);
		this->generateAALOAD(source, temp_0F7C);
		goto L15C6;
	L0F85: //
		temp_0F88 = (InstructionBALOAD*)((instruction).getValue());
		temp_0F88->checkCast(InstructionBALOAD::__thisClassStatic);
		this->generateBALOAD(source, temp_0F88);
		goto L15C6;
	L0F91: //
		temp_0F94 = (InstructionCALOAD*)((instruction).getValue());
		temp_0F94->checkCast(InstructionCALOAD::__thisClassStatic);
		this->generateCALOAD(source, temp_0F94);
		goto L15C6;
	L0F9D: //
		temp_0FA0 = (InstructionSALOAD*)((instruction).getValue());
		temp_0FA0->checkCast(InstructionSALOAD::__thisClassStatic);
		this->generateSALOAD(source, temp_0FA0);
		goto L15C6;
	L0FA9: //
		temp_0FAC = (InstructionISTORE*)((instruction).getValue());
		temp_0FAC->checkCast(InstructionISTORE::__thisClassStatic);
		this->generateISTORE(source, temp_0FAC);
		goto L15C6;
	L0FB5: //
		temp_0FB8 = (InstructionLSTORE*)((instruction).getValue());
		temp_0FB8->checkCast(InstructionLSTORE::__thisClassStatic);
		this->generateLSTORE(source, temp_0FB8);
		goto L15C6;
	L0FC1: //
		temp_0FC4 = (InstructionFSTORE*)((instruction).getValue());
		temp_0FC4->checkCast(InstructionFSTORE::__thisClassStatic);
		this->generateFSTORE(source, temp_0FC4);
		goto L15C6;
	L0FCD: //
		temp_0FD0 = (InstructionDSTORE*)((instruction).getValue());
		temp_0FD0->checkCast(InstructionDSTORE::__thisClassStatic);
		this->generateDSTORE(source, temp_0FD0);
		goto L15C6;
	L0FD9: //
		temp_0FDC = (InstructionASTORE*)((instruction).getValue());
		temp_0FDC->checkCast(InstructionASTORE::__thisClassStatic);
		this->generateASTORE(source, temp_0FDC);
		goto L15C6;
	L0FE5: //
		temp_0FE8 = (InstructionIASTORE*)((instruction).getValue());
		temp_0FE8->checkCast(InstructionIASTORE::__thisClassStatic);
		this->generateIASTORE(source, temp_0FE8);
		goto L15C6;
	L0FF1: //
		temp_0FF4 = (InstructionLASTORE*)((instruction).getValue());
		temp_0FF4->checkCast(InstructionLASTORE::__thisClassStatic);
		this->generateLASTORE(source, temp_0FF4);
		goto L15C6;
	L0FFD: //
		temp_1000 = (InstructionFASTORE*)((instruction).getValue());
		temp_1000->checkCast(InstructionFASTORE::__thisClassStatic);
		this->generateFASTORE(source, temp_1000);
		goto L15C6;
	L1009: //
		temp_100C = (InstructionDASTORE*)((instruction).getValue());
		temp_100C->checkCast(InstructionDASTORE::__thisClassStatic);
		this->generateDASTORE(source, temp_100C);
		goto L15C6;
	L1015: //
		temp_1018 = (InstructionAASTORE*)((instruction).getValue());
		temp_1018->checkCast(InstructionAASTORE::__thisClassStatic);
		this->generateAASTORE(source, temp_1018);
		goto L15C6;
	L1021: //
		temp_1024 = (InstructionBASTORE*)((instruction).getValue());
		temp_1024->checkCast(InstructionBASTORE::__thisClassStatic);
		this->generateBASTORE(source, temp_1024);
		goto L15C6;
	L102D: //
		temp_1030 = (InstructionCASTORE*)((instruction).getValue());
		temp_1030->checkCast(InstructionCASTORE::__thisClassStatic);
		this->generateCASTORE(source, temp_1030);
		goto L15C6;
	L1039: //
		temp_103C = (InstructionSASTORE*)((instruction).getValue());
		temp_103C->checkCast(InstructionSASTORE::__thisClassStatic);
		this->generateSASTORE(source, temp_103C);
		goto L15C6;
	L1045: //
		temp_1048 = (InstructionPOP*)((instruction).getValue());
		temp_1048->checkCast(InstructionPOP::__thisClassStatic);
		this->generatePOP(source, temp_1048);
		goto L15C6;
	L1051: //
		temp_1054 = (InstructionPOP2*)((instruction).getValue());
		temp_1054->checkCast(InstructionPOP2::__thisClassStatic);
		this->generatePOP2(source, temp_1054);
		goto L15C6;
	L105D: //
		temp_1060 = (InstructionDUP*)((instruction).getValue());
		temp_1060->checkCast(InstructionDUP::__thisClassStatic);
		this->generateDUP(source, temp_1060);
		goto L15C6;
	L1069: //
		temp_106C = (InstructionDUP_X1*)((instruction).getValue());
		temp_106C->checkCast(InstructionDUP_X1::__thisClassStatic);
		this->generateDUP_X1(source, temp_106C);
		goto L15C6;
	L1075: //
		temp_1078 = (InstructionDUP_X2*)((instruction).getValue());
		temp_1078->checkCast(InstructionDUP_X2::__thisClassStatic);
		this->generateDUP_X2(source, temp_1078);
		goto L15C6;
	L1081: //
		temp_1084 = (InstructionDUP2*)((instruction).getValue());
		temp_1084->checkCast(InstructionDUP2::__thisClassStatic);
		this->generateDUP2(source, temp_1084);
		goto L15C6;
	L108D: //
		temp_1090 = (InstructionDUP2_X1*)((instruction).getValue());
		temp_1090->checkCast(InstructionDUP2_X1::__thisClassStatic);
		this->generateDUP2_X1(source, temp_1090);
		goto L15C6;
	L1099: //
		temp_109C = (InstructionDUP2_X2*)((instruction).getValue());
		temp_109C->checkCast(InstructionDUP2_X2::__thisClassStatic);
		this->generateDUP2_X2(source, temp_109C);
		goto L15C6;
	L10A5: //
		temp_10A8 = (InstructionSWAP*)((instruction).getValue());
		temp_10A8->checkCast(InstructionSWAP::__thisClassStatic);
		this->generateSWAP(source, temp_10A8);
		goto L15C6;
	L10B1: //
		temp_10B4 = (InstructionIADD*)((instruction).getValue());
		temp_10B4->checkCast(InstructionIADD::__thisClassStatic);
		this->generateIADD(source, temp_10B4);
		goto L15C6;
	L10BD: //
		temp_10C0 = (InstructionLADD*)((instruction).getValue());
		temp_10C0->checkCast(InstructionLADD::__thisClassStatic);
		this->generateLADD(source, temp_10C0);
		goto L15C6;
	L10C9: //
		temp_10CC = (InstructionFADD*)((instruction).getValue());
		temp_10CC->checkCast(InstructionFADD::__thisClassStatic);
		this->generateFADD(source, temp_10CC);
		goto L15C6;
	L10D5: //
		temp_10D8 = (InstructionDADD*)((instruction).getValue());
		temp_10D8->checkCast(InstructionDADD::__thisClassStatic);
		this->generateDADD(source, temp_10D8);
		goto L15C6;
	L10E1: //
		temp_10E4 = (InstructionISUB*)((instruction).getValue());
		temp_10E4->checkCast(InstructionISUB::__thisClassStatic);
		this->generateISUB(source, temp_10E4);
		goto L15C6;
	L10ED: //
		temp_10F0 = (InstructionLSUB*)((instruction).getValue());
		temp_10F0->checkCast(InstructionLSUB::__thisClassStatic);
		this->generateLSUB(source, temp_10F0);
		goto L15C6;
	L10F9: //
		temp_10FC = (InstructionFSUB*)((instruction).getValue());
		temp_10FC->checkCast(InstructionFSUB::__thisClassStatic);
		this->generateFSUB(source, temp_10FC);
		goto L15C6;
	L1105: //
		temp_1108 = (InstructionDSUB*)((instruction).getValue());
		temp_1108->checkCast(InstructionDSUB::__thisClassStatic);
		this->generateDSUB(source, temp_1108);
		goto L15C6;
	L1111: //
		temp_1114 = (InstructionIMUL*)((instruction).getValue());
		temp_1114->checkCast(InstructionIMUL::__thisClassStatic);
		this->generateIMUL(source, temp_1114);
		goto L15C6;
	L111D: //
		temp_1120 = (InstructionLMUL*)((instruction).getValue());
		temp_1120->checkCast(InstructionLMUL::__thisClassStatic);
		this->generateLMUL(source, temp_1120);
		goto L15C6;
	L1129: //
		temp_112C = (InstructionFMUL*)((instruction).getValue());
		temp_112C->checkCast(InstructionFMUL::__thisClassStatic);
		this->generateFMUL(source, temp_112C);
		goto L15C6;
	L1135: //
		temp_1138 = (InstructionDMUL*)((instruction).getValue());
		temp_1138->checkCast(InstructionDMUL::__thisClassStatic);
		this->generateDMUL(source, temp_1138);
		goto L15C6;
	L1141: //
		temp_1144 = (InstructionIDIV*)((instruction).getValue());
		temp_1144->checkCast(InstructionIDIV::__thisClassStatic);
		this->generateIDIV(source, temp_1144);
		goto L15C6;
	L114D: //
		temp_1150 = (InstructionLDIV*)((instruction).getValue());
		temp_1150->checkCast(InstructionLDIV::__thisClassStatic);
		this->generateLDIV(source, temp_1150);
		goto L15C6;
	L1159: //
		temp_115C = (InstructionFDIV*)((instruction).getValue());
		temp_115C->checkCast(InstructionFDIV::__thisClassStatic);
		this->generateFDIV(source, temp_115C);
		goto L15C6;
	L1165: //
		temp_1168 = (InstructionDDIV*)((instruction).getValue());
		temp_1168->checkCast(InstructionDDIV::__thisClassStatic);
		this->generateDDIV(source, temp_1168);
		goto L15C6;
	L1171: //
		temp_1174 = (InstructionIREM*)((instruction).getValue());
		temp_1174->checkCast(InstructionIREM::__thisClassStatic);
		this->generateIREM(source, temp_1174);
		goto L15C6;
	L117D: //
		temp_1180 = (InstructionLREM*)((instruction).getValue());
		temp_1180->checkCast(InstructionLREM::__thisClassStatic);
		this->generateLREM(source, temp_1180);
		goto L15C6;
	L1189: //
		temp_118C = (InstructionFREM*)((instruction).getValue());
		temp_118C->checkCast(InstructionFREM::__thisClassStatic);
		this->generateFREM(source, temp_118C);
		goto L15C6;
	L1195: //
		temp_1198 = (InstructionDREM*)((instruction).getValue());
		temp_1198->checkCast(InstructionDREM::__thisClassStatic);
		this->generateDREM(source, temp_1198);
		goto L15C6;
	L11A1: //
		temp_11A4 = (InstructionINEG*)((instruction).getValue());
		temp_11A4->checkCast(InstructionINEG::__thisClassStatic);
		this->generateINEG(source, temp_11A4);
		goto L15C6;
	L11AD: //
		temp_11B0 = (InstructionLNEG*)((instruction).getValue());
		temp_11B0->checkCast(InstructionLNEG::__thisClassStatic);
		this->generateLNEG(source, temp_11B0);
		goto L15C6;
	L11B9: //
		temp_11BC = (InstructionFNEG*)((instruction).getValue());
		temp_11BC->checkCast(InstructionFNEG::__thisClassStatic);
		this->generateFNEG(source, temp_11BC);
		goto L15C6;
	L11C5: //
		temp_11C8 = (InstructionDNEG*)((instruction).getValue());
		temp_11C8->checkCast(InstructionDNEG::__thisClassStatic);
		this->generateDNEG(source, temp_11C8);
		goto L15C6;
	L11D1: //
		temp_11D4 = (InstructionISHL*)((instruction).getValue());
		temp_11D4->checkCast(InstructionISHL::__thisClassStatic);
		this->generateISHL(source, temp_11D4);
		goto L15C6;
	L11DD: //
		temp_11E0 = (InstructionLSHL*)((instruction).getValue());
		temp_11E0->checkCast(InstructionLSHL::__thisClassStatic);
		this->generateLSHL(source, temp_11E0);
		goto L15C6;
	L11E9: //
		temp_11EC = (InstructionISHR*)((instruction).getValue());
		temp_11EC->checkCast(InstructionISHR::__thisClassStatic);
		this->generateISHR(source, temp_11EC);
		goto L15C6;
	L11F5: //
		temp_11F8 = (InstructionLSHR*)((instruction).getValue());
		temp_11F8->checkCast(InstructionLSHR::__thisClassStatic);
		this->generateLSHR(source, temp_11F8);
		goto L15C6;
	L1201: //
		temp_1204 = (InstructionIUSHR*)((instruction).getValue());
		temp_1204->checkCast(InstructionIUSHR::__thisClassStatic);
		this->generateIUSHR(source, temp_1204);
		goto L15C6;
	L120D: //
		temp_1210 = (InstructionLUSHR*)((instruction).getValue());
		temp_1210->checkCast(InstructionLUSHR::__thisClassStatic);
		this->generateLUSHR(source, temp_1210);
		goto L15C6;
	L1219: //
		temp_121C = (InstructionIAND*)((instruction).getValue());
		temp_121C->checkCast(InstructionIAND::__thisClassStatic);
		this->generateIAND(source, temp_121C);
		goto L15C6;
	L1225: //
		temp_1228 = (InstructionLAND*)((instruction).getValue());
		temp_1228->checkCast(InstructionLAND::__thisClassStatic);
		this->generateLAND(source, temp_1228);
		goto L15C6;
	L1231: //
		temp_1234 = (InstructionIOR*)((instruction).getValue());
		temp_1234->checkCast(InstructionIOR::__thisClassStatic);
		this->generateIOR(source, temp_1234);
		goto L15C6;
	L123D: //
		temp_1240 = (InstructionLOR*)((instruction).getValue());
		temp_1240->checkCast(InstructionLOR::__thisClassStatic);
		this->generateLOR(source, temp_1240);
		goto L15C6;
	L1249: //
		temp_124C = (InstructionIXOR*)((instruction).getValue());
		temp_124C->checkCast(InstructionIXOR::__thisClassStatic);
		this->generateIXOR(source, temp_124C);
		goto L15C6;
	L1255: //
		temp_1258 = (InstructionLXOR*)((instruction).getValue());
		temp_1258->checkCast(InstructionLXOR::__thisClassStatic);
		this->generateLXOR(source, temp_1258);
		goto L15C6;
	L1261: //
		temp_1264 = (InstructionIINC*)((instruction).getValue());
		temp_1264->checkCast(InstructionIINC::__thisClassStatic);
		this->generateIINC(source, temp_1264);
		goto L15C6;
	L126D: //
		temp_1270 = (InstructionI2L*)((instruction).getValue());
		temp_1270->checkCast(InstructionI2L::__thisClassStatic);
		this->generateI2L(source, temp_1270);
		goto L15C6;
	L1279: //
		temp_127C = (InstructionI2F*)((instruction).getValue());
		temp_127C->checkCast(InstructionI2F::__thisClassStatic);
		this->generateI2F(source, temp_127C);
		goto L15C6;
	L1285: //
		temp_1288 = (InstructionI2D*)((instruction).getValue());
		temp_1288->checkCast(InstructionI2D::__thisClassStatic);
		this->generateI2D(source, temp_1288);
		goto L15C6;
	L1291: //
		temp_1294 = (InstructionL2I*)((instruction).getValue());
		temp_1294->checkCast(InstructionL2I::__thisClassStatic);
		this->generateL2I(source, temp_1294);
		goto L15C6;
	L129D: //
		temp_12A0 = (InstructionL2F*)((instruction).getValue());
		temp_12A0->checkCast(InstructionL2F::__thisClassStatic);
		this->generateL2F(source, temp_12A0);
		goto L15C6;
	L12A9: //
		temp_12AC = (InstructionL2D*)((instruction).getValue());
		temp_12AC->checkCast(InstructionL2D::__thisClassStatic);
		this->generateL2D(source, temp_12AC);
		goto L15C6;
	L12B5: //
		temp_12B8 = (InstructionF2I*)((instruction).getValue());
		temp_12B8->checkCast(InstructionF2I::__thisClassStatic);
		this->generateF2I(source, temp_12B8);
		goto L15C6;
	L12C1: //
		temp_12C4 = (InstructionF2L*)((instruction).getValue());
		temp_12C4->checkCast(InstructionF2L::__thisClassStatic);
		this->generateF2L(source, temp_12C4);
		goto L15C6;
	L12CD: //
		temp_12D0 = (InstructionF2D*)((instruction).getValue());
		temp_12D0->checkCast(InstructionF2D::__thisClassStatic);
		this->generateF2D(source, temp_12D0);
		goto L15C6;
	L12D9: //
		temp_12DC = (InstructionD2I*)((instruction).getValue());
		temp_12DC->checkCast(InstructionD2I::__thisClassStatic);
		this->generateD2I(source, temp_12DC);
		goto L15C6;
	L12E5: //
		temp_12E8 = (InstructionD2L*)((instruction).getValue());
		temp_12E8->checkCast(InstructionD2L::__thisClassStatic);
		this->generateD2L(source, temp_12E8);
		goto L15C6;
	L12F1: //
		temp_12F4 = (InstructionD2F*)((instruction).getValue());
		temp_12F4->checkCast(InstructionD2F::__thisClassStatic);
		this->generateD2F(source, temp_12F4);
		goto L15C6;
	L12FD: //
		temp_1300 = (InstructionI2B*)((instruction).getValue());
		temp_1300->checkCast(InstructionI2B::__thisClassStatic);
		this->generateI2B(source, temp_1300);
		goto L15C6;
	L1309: //
		temp_130C = (InstructionI2C*)((instruction).getValue());
		temp_130C->checkCast(InstructionI2C::__thisClassStatic);
		this->generateI2C(source, temp_130C);
		goto L15C6;
	L1315: //
		temp_1318 = (InstructionI2S*)((instruction).getValue());
		temp_1318->checkCast(InstructionI2S::__thisClassStatic);
		this->generateI2S(source, temp_1318);
		goto L15C6;
	L1321: //
		temp_1324 = (InstructionLCMP*)((instruction).getValue());
		temp_1324->checkCast(InstructionLCMP::__thisClassStatic);
		this->generateLCMP(source, temp_1324);
		goto L15C6;
	L132D: //
		temp_1330 = (InstructionFCMPL*)((instruction).getValue());
		temp_1330->checkCast(InstructionFCMPL::__thisClassStatic);
		this->generateFCMPL(source, temp_1330);
		goto L15C6;
	L1339: //
		temp_133C = (InstructionFCMPG*)((instruction).getValue());
		temp_133C->checkCast(InstructionFCMPG::__thisClassStatic);
		this->generateFCMPG(source, temp_133C);
		goto L15C6;
	L1345: //
		temp_1348 = (InstructionDCMPL*)((instruction).getValue());
		temp_1348->checkCast(InstructionDCMPL::__thisClassStatic);
		this->generateDCMPL(source, temp_1348);
		goto L15C6;
	L1351: //
		temp_1354 = (InstructionDCMPG*)((instruction).getValue());
		temp_1354->checkCast(InstructionDCMPG::__thisClassStatic);
		this->generateDCMPG(source, temp_1354);
		goto L15C6;
	L135D: //
		temp_1360 = (InstructionIFEQ*)((instruction).getValue());
		temp_1360->checkCast(InstructionIFEQ::__thisClassStatic);
		this->generateIFEQ(source, temp_1360);
		goto L15C6;
	L1369: //
		temp_136C = (InstructionIFNE*)((instruction).getValue());
		temp_136C->checkCast(InstructionIFNE::__thisClassStatic);
		this->generateIFNE(source, temp_136C);
		goto L15C6;
	L1375: //
		temp_1378 = (InstructionIFLT*)((instruction).getValue());
		temp_1378->checkCast(InstructionIFLT::__thisClassStatic);
		this->generateIFLT(source, temp_1378);
		goto L15C6;
	L1381: //
		temp_1384 = (InstructionIFGE*)((instruction).getValue());
		temp_1384->checkCast(InstructionIFGE::__thisClassStatic);
		this->generateIFGE(source, temp_1384);
		goto L15C6;
	L138D: //
		temp_1390 = (InstructionIFGT*)((instruction).getValue());
		temp_1390->checkCast(InstructionIFGT::__thisClassStatic);
		this->generateIFGT(source, temp_1390);
		goto L15C6;
	L1399: //
		temp_139C = (InstructionIFLE*)((instruction).getValue());
		temp_139C->checkCast(InstructionIFLE::__thisClassStatic);
		this->generateIFLE(source, temp_139C);
		goto L15C6;
	L13A5: //
		temp_13A8 = (InstructionIF_ICMPEQ*)((instruction).getValue());
		temp_13A8->checkCast(InstructionIF_ICMPEQ::__thisClassStatic);
		this->generateIF_ICMPEQ(source, temp_13A8);
		goto L15C6;
	L13B1: //
		temp_13B4 = (InstructionIF_ICMPNE*)((instruction).getValue());
		temp_13B4->checkCast(InstructionIF_ICMPNE::__thisClassStatic);
		this->generateIF_ICMPNE(source, temp_13B4);
		goto L15C6;
	L13BD: //
		temp_13C0 = (InstructionIF_ICMPLT*)((instruction).getValue());
		temp_13C0->checkCast(InstructionIF_ICMPLT::__thisClassStatic);
		this->generateIF_ICMPLT(source, temp_13C0);
		goto L15C6;
	L13C9: //
		temp_13CC = (InstructionIF_ICMPGE*)((instruction).getValue());
		temp_13CC->checkCast(InstructionIF_ICMPGE::__thisClassStatic);
		this->generateIF_ICMPGE(source, temp_13CC);
		goto L15C6;
	L13D5: //
		temp_13D8 = (InstructionIF_ICMPGT*)((instruction).getValue());
		temp_13D8->checkCast(InstructionIF_ICMPGT::__thisClassStatic);
		this->generateIF_ICMPGT(source, temp_13D8);
		goto L15C6;
	L13E1: //
		temp_13E4 = (InstructionIF_ICMPLE*)((instruction).getValue());
		temp_13E4->checkCast(InstructionIF_ICMPLE::__thisClassStatic);
		this->generateIF_ICMPLE(source, temp_13E4);
		goto L15C6;
	L13ED: //
		temp_13F0 = (InstructionIF_ACMPEQ*)((instruction).getValue());
		temp_13F0->checkCast(InstructionIF_ACMPEQ::__thisClassStatic);
		this->generateIF_ACMPEQ(source, temp_13F0);
		goto L15C6;
	L13F9: //
		temp_13FC = (InstructionIF_ACMPNE*)((instruction).getValue());
		temp_13FC->checkCast(InstructionIF_ACMPNE::__thisClassStatic);
		this->generateIF_ACMPNE(source, temp_13FC);
		goto L15C6;
	L1405: //
		temp_1408 = (InstructionGOTO*)((instruction).getValue());
		temp_1408->checkCast(InstructionGOTO::__thisClassStatic);
		this->generateGOTO(source, temp_1408);
		goto L15C6;
	L1411: //
		temp_1414 = (InstructionJSR*)((instruction).getValue());
		temp_1414->checkCast(InstructionJSR::__thisClassStatic);
		this->generateJSR(source, temp_1414);
		goto L15C6;
	L141D: //
		temp_1420 = (InstructionRET*)((instruction).getValue());
		temp_1420->checkCast(InstructionRET::__thisClassStatic);
		this->generateRET(source, temp_1420);
		goto L15C6;
	L1429: //
		temp_142C = (InstructionTABLESWITCH*)((instruction).getValue());
		temp_142C->checkCast(InstructionTABLESWITCH::__thisClassStatic);
		this->generateTABLESWITCH(source, temp_142C);
		goto L15C6;
	L1435: //
		temp_1438 = (InstructionLOOKUPSWITCH*)((instruction).getValue());
		temp_1438->checkCast(InstructionLOOKUPSWITCH::__thisClassStatic);
		this->generateLOOKUPSWITCH(source, temp_1438);
		goto L15C6;
	L1441: //
		temp_1444 = (InstructionIRETURN*)((instruction).getValue());
		temp_1444->checkCast(InstructionIRETURN::__thisClassStatic);
		this->generateIRETURN(source, temp_1444);
		goto L15C6;
	L144D: //
		temp_1450 = (InstructionLRETURN*)((instruction).getValue());
		temp_1450->checkCast(InstructionLRETURN::__thisClassStatic);
		this->generateLRETURN(source, temp_1450);
		goto L15C6;
	L1459: //
		temp_145C = (InstructionFRETURN*)((instruction).getValue());
		temp_145C->checkCast(InstructionFRETURN::__thisClassStatic);
		this->generateFRETURN(source, temp_145C);
		goto L15C6;
	L1465: //
		temp_1468 = (InstructionDRETURN*)((instruction).getValue());
		temp_1468->checkCast(InstructionDRETURN::__thisClassStatic);
		this->generateDRETURN(source, temp_1468);
		goto L15C6;
	L1471: //
		temp_1474 = (InstructionARETURN*)((instruction).getValue());
		temp_1474->checkCast(InstructionARETURN::__thisClassStatic);
		this->generateARETURN(source, temp_1474);
		goto L15C6;
	L147D: //
		temp_1480 = (InstructionRETURN*)((instruction).getValue());
		temp_1480->checkCast(InstructionRETURN::__thisClassStatic);
		this->generateRETURN(source, temp_1480);
		goto L15C6;
	L1489: //
		temp_148C = (InstructionGETSTATIC*)((instruction).getValue());
		temp_148C->checkCast(InstructionGETSTATIC::__thisClassStatic);
		this->generateGETSTATIC(source, temp_148C);
		goto L15C6;
	L1495: //
		temp_1498 = (InstructionPUTSTATIC*)((instruction).getValue());
		temp_1498->checkCast(InstructionPUTSTATIC::__thisClassStatic);
		this->generatePUTSTATIC(source, temp_1498);
		goto L15C6;
	L14A1: //
		temp_14A4 = (InstructionGETFIELD*)((instruction).getValue());
		temp_14A4->checkCast(InstructionGETFIELD::__thisClassStatic);
		this->generateGETFIELD(source, temp_14A4);
		goto L15C6;
	L14AD: //
		temp_14B0 = (InstructionPUTFIELD*)((instruction).getValue());
		temp_14B0->checkCast(InstructionPUTFIELD::__thisClassStatic);
		this->generatePUTFIELD(source, temp_14B0);
		goto L15C6;
	L14B9: //
		temp_14BC = (InstructionINVOKEVIRTUAL*)((instruction).getValue());
		temp_14BC->checkCast(InstructionINVOKEVIRTUAL::__thisClassStatic);
		this->generateINVOKEVIRTUAL(source, temp_14BC);
		goto L15C6;
	L14C5: //
		temp_14C8 = (InstructionINVOKESPECIAL*)((instruction).getValue());
		temp_14C8->checkCast(InstructionINVOKESPECIAL::__thisClassStatic);
		this->generateINVOKESPECIAL(source, temp_14C8);
		goto L15C6;
	L14D1: //
		temp_14D4 = (InstructionINVOKESTATIC*)((instruction).getValue());
		temp_14D4->checkCast(InstructionINVOKESTATIC::__thisClassStatic);
		this->generateINVOKESTATIC(source, temp_14D4);
		goto L15C6;
	L14DD: //
		temp_14E0 = (InstructionINVOKEINTERFACE*)((instruction).getValue());
		temp_14E0->checkCast(InstructionINVOKEINTERFACE::__thisClassStatic);
		this->generateINVOKEINTERFACE(source, temp_14E0);
		goto L15C6;
	L14E9: //
		temp_14EC = (InstructionINVOKEDYNAMIC*)((instruction).getValue());
		temp_14EC->checkCast(InstructionINVOKEDYNAMIC::__thisClassStatic);
		this->generateINVOKEDYNAMIC(source, temp_14EC);
		goto L15C6;
	L14F5: //
		temp_14F8 = (InstructionNEW*)((instruction).getValue());
		temp_14F8->checkCast(InstructionNEW::__thisClassStatic);
		this->generateNEW(source, temp_14F8);
		goto L15C6;
	L1501: //
		temp_1504 = (InstructionNEWARRAY*)((instruction).getValue());
		temp_1504->checkCast(InstructionNEWARRAY::__thisClassStatic);
		this->generateNEWARRAY(source, temp_1504);
		goto L15C6;
	L150D: //
		temp_1510 = (InstructionANEWARRAY*)((instruction).getValue());
		temp_1510->checkCast(InstructionANEWARRAY::__thisClassStatic);
		this->generateANEWARRAY(source, temp_1510);
		goto L15C6;
	L1519: //
		temp_151C = (InstructionARRAYLENGTH*)((instruction).getValue());
		temp_151C->checkCast(InstructionARRAYLENGTH::__thisClassStatic);
		this->generateARRAYLENGTH(source, temp_151C);
		goto L15C6;
	L1525: //
		temp_1528 = (InstructionATHROW*)((instruction).getValue());
		temp_1528->checkCast(InstructionATHROW::__thisClassStatic);
		this->generateATHROW(source, temp_1528);
		goto L15C6;
	L1531: //
		temp_1534 = (InstructionCHECKCAST*)((instruction).getValue());
		temp_1534->checkCast(InstructionCHECKCAST::__thisClassStatic);
		this->generateCHECKCAST(source, temp_1534);
		goto L15C6;
	L153D: //
		temp_1540 = (InstructionINSTANCEOF*)((instruction).getValue());
		temp_1540->checkCast(InstructionINSTANCEOF::__thisClassStatic);
		this->generateINSTANCEOF(source, temp_1540);
		goto L15C6;
	L1549: //
		temp_154C = (InstructionMONITORENTER*)((instruction).getValue());
		temp_154C->checkCast(InstructionMONITORENTER::__thisClassStatic);
		this->generateMONITORENTER(source, temp_154C);
		goto L15C6;
	L1555: //
		temp_1558 = (InstructionMONITOREXIT*)((instruction).getValue());
		temp_1558->checkCast(InstructionMONITOREXIT::__thisClassStatic);
		this->generateMONITOREXIT(source, temp_1558);
		goto L15C6;
	L1561: //
		temp_1564 = (InstructionWIDE*)((instruction).getValue());
		temp_1564->checkCast(InstructionWIDE::__thisClassStatic);
		this->generateWIDE(source, temp_1564);
		goto L15C6;
	L156D: //
		temp_1570 = (InstructionMULTIANEWARRAY*)((instruction).getValue());
		temp_1570->checkCast(InstructionMULTIANEWARRAY::__thisClassStatic);
		this->generateMULTIANEWARRAY(source, temp_1570);
		goto L15C6;
	L1579: //
		temp_157C = (InstructionIFNULL*)((instruction).getValue());
		temp_157C->checkCast(InstructionIFNULL::__thisClassStatic);
		this->generateIFNULL(source, temp_157C);
		goto L15C6;
	L1585: //
		temp_1588 = (InstructionIFNONNULL*)((instruction).getValue());
		temp_1588->checkCast(InstructionIFNONNULL::__thisClassStatic);
		this->generateIFNONNULL(source, temp_1588);
		goto L15C6;
	L1591: //
		temp_1594 = (InstructionGOTO_W*)((instruction).getValue());
		temp_1594->checkCast(InstructionGOTO_W::__thisClassStatic);
		this->generateGOTO_W(source, temp_1594);
		goto L15C6;
	L159D: //
		temp_15A0 = (InstructionJSR_W*)((instruction).getValue());
		temp_15A0->checkCast(InstructionJSR_W::__thisClassStatic);
		this->generateJSR_W(source, temp_15A0);
		goto L15C6;
	L15A9: //
		System::__ClassInit();
		temp_15B3 = new StringBuilder(createString("Instruction "));
		System::out->println(temp_15B3->append(opcode_017B)->append(createString(" execution not supported"))->toString());
	L15C6: //
		return;
	}

	int CppExecutionContext::getCodeSize()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->codeSize;
	}

	Pointer<LocalVariable> CppExecutionContext::getLocalVariable(int index, int address)
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->locals->get(index, address);
	}

	Pointer<ArrayList<LocalVariable>> CppExecutionContext::getLocalVariables()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->locals->getVariables();
	}

	bool CppExecutionContext::hasLabel(int address)
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->labels->get(address);
	}

	Pointer<String> CppExecutionContext::typeSimplifier(Pointer<String> type)
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->cppClass->simplifyType(type);
	}

	Pointer<String> CppExecutionContext::addTemplateParameters(Pointer<String> className)
	{
		UsageCounterMaintainer maintainer(this, true);

		int templateCount_0009 = 0;
		Pointer<ArrayList<String>> params_0015;
		int i_0018 = 0;
		Pointer<String> parameters_003C;
		Pointer<ArrayList<Object>> temp_0011;
		Pointer<JavaArray<String>> temp_002E;
		Pointer<JavaArray<String>> temp_0034;
		Pointer<StringBuilder> temp_0043;
		templateCount_0009 = this->cppClass->getTemplateParameterCount(className);
		if ((templateCount_0009) <= 0)
			goto L0055;
		temp_0011 = new ArrayList<Object>();
		params_0015 = (ArrayList<String>*)(temp_0011.getValue());
		i_0018 = 0;
		goto L0026;
	L001B: //
		params_0015->add(createString("Object"));
		i_0018 += 1;
	L0026: //
		if ((i_0018) < (templateCount_0009))
			goto L001B;
		temp_002E = new JavaArray<String>(templateCount_0009);
		temp_0034 = (JavaArray<String>*)((params_0015->toArray(temp_002E.getValue())).getValue());
		temp_0034->checkCast(JavaArray<String>::__thisClassStatic);
		Statics::__ClassInit();
		parameters_003C = Statics::commaSeparatedList(temp_0034);
		temp_0043 = new StringBuilder(createString("<"));
		return temp_0043->append(parameters_003C)->append(createString(">"))->toString();
	L0055: //
		return createString("");
	}

	Pointer<ClassFile> CppExecutionContext::findClassByName(Pointer<String> simpleClassName)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> fullClassName_000B;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_001B;
		Pointer<ClassFile> temp_0035;
		Recomp::__ClassInit();
		temp_0007 = (String*)((Recomp::simpleClassNames->get(simpleClassName.getValue())).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		fullClassName_000B = temp_0007;
		temp_001B = new StringBuilder(createString("Full class with simple name "));
		Statics::__ClassInit();
		Statics::Assert(((((fullClassName_000B).getValue() != nullptr) ? (1) : (0))) != 0, temp_001B->append(simpleClassName)->append(createString(" not found"))->toString());
		Recomp::__ClassInit();
		temp_0035 = (ClassFile*)((Recomp::processedClasses->get(fullClassName_000B.getValue())).getValue());
		temp_0035->checkCast(ClassFile::__thisClassStatic);
		return temp_0035;
	}

	void CppExecutionContext::generateAALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionAALOAD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> index_0010;
		Pointer<JavaArray<String>> array_0021;
		Pointer<String> arrayElementType_0049;
		Pointer<String> newEntry_0078;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_0052;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		index_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		array_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(array_0021->get(0)->startsWith(createString("JavaArray<")), createString("AALOAD: Array expected"));
		Statics::__ClassInit();
		Statics::Assert(index_0010->get(0)->equals(createString("int")), createString("AALOAD: Integer index expected"));
		Statics::__ClassInit();
		arrayElementType_0049 = Statics::removeJavaArray(array_0021->get(0));
		String::__ClassInit();
		temp_0052 = new StringBuilder(String::valueOf(arrayElementType_0049.getValue()));
		newEntry_0078 = temp_0052->append(createString("\t"))->append(array_0021->get(1))->append(createString("->get("))->append(index_0010->get(1))->append(createString(")"))->toString();
		this->stack->push(newEntry_0078.getValue());
		return;
	}

	void CppExecutionContext::generateAASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionAASTORE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> value_0010;
		Pointer<JavaArray<String>> index_0021;
		Pointer<JavaArray<String>> array_0032;
		Pointer<String> arrayElementType_005B;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<String> temp_0028;
		Pointer<StringBuilder> temp_0089;
		Pointer<StringBuilder> temp_00A8;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		value_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		index_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		temp_0028 = (String*)((this->stack->pop()).getValue());
		temp_0028->checkCast(String::__thisClassStatic);
		array_0032 = (JavaArray<String>*)(temp_0028->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(array_0032->get(0)->startsWith(createString("JavaArray<")), createString("AASTORE: Array expected"));
		Statics::__ClassInit();
		Statics::Assert(index_0021->get(0)->equals(createString("int")), createString("AASTORE: Integer index expected"));
		Statics::__ClassInit();
		arrayElementType_005B = Statics::removeJavaArray(array_0032->get(0));
		Statics::__ClassInit();
		Statics::Assert(value_0010->get(0)->equals(arrayElementType_005B.getValue()), createString("AASTORE: Value does not match JavaArray type"));
		if (!(value_0010->get(0)->equals(createString("String"))))
			goto L009C;
		if (!(value_0010->get(1)->startsWith(createString("\""))))
			goto L009C;
		temp_0089 = new StringBuilder(createString("createString("));
		value_0010->assign(1, temp_0089->append(value_0010->get(1))->append(createString(")"))->toString());
	L009C: //
		String::__ClassInit();
		temp_00A8 = new StringBuilder(String::valueOf(array_0032->get(1).getValue()));
		source->iprintln(temp_00A8->append(createString("->assign("))->append(index_0021->get(1))->append(createString(", "))->append(value_0010->get(1))->append(createString(");"))->toString());
		return;
	}

	void CppExecutionContext::generateACONST_NULL(Pointer<IndentedOutputStream> source, Pointer<InstructionACONST_NULL> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> newEntry_0004;
		newEntry_0004 = createString("nullptr\tnullptr");
		this->stack->push(newEntry_0004.getValue());
		return;
	}

	void CppExecutionContext::generateALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionALOAD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		int index_0005 = 0;
		Pointer<LocalVariable> local_0032;
		Pointer<StringBuilder> temp_0043;
		Pointer<StringBuilder> temp_0066;
		index_0005 = instruction->getIndex();
		Statics::__ClassInit();
		Statics::Assert(((((index_0005) >= 0) ? (1) : (0))) != 0, createString("ALOAD: index out of range"));
		Statics::__ClassInit();
		Statics::Assert(((((index_0005) < (this->maxLocals)) ? (1) : (0))) != 0, createString("ALOAD: index out of range"));
		local_0032 = this->locals->get(index_0005, instruction.getValue());
		temp_0043 = new StringBuilder(createString("Local at "));
		Statics::__ClassInit();
		Statics::Assert(((((local_0032).getValue() != nullptr) ? (1) : (0))) != 0, temp_0043->append(index_0005)->append(createString(" is not available"))->toString());
		String::__ClassInit();
		temp_0066 = new StringBuilder(String::valueOf(local_0032->getType().getValue()));
		this->stack->push(temp_0066->append(createString("\t"))->append(local_0032->getName())->toString().getValue());
		return;
	}

	void CppExecutionContext::generateANEWARRAY(Pointer<IndentedOutputStream> source, Pointer<InstructionANEWARRAY> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> length_0024;
		Pointer<String> type_002A;
		Pointer<String> simpleType_003C;
		Pointer<String> tempName_0056;
		Pointer<String> newEntry_00D1;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_0043;
		Pointer<StringBuilder> temp_005F;
		Pointer<StringBuilder> temp_0088;
		Pointer<StringBuilder> temp_00B4;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(topOfStack_0010->get(0)->equals(createString("int")), createString("ANEWARRAY: Integer operand expected"));
		length_0024 = topOfStack_0010->get(1);
		type_002A = instruction->getClassName();
		Statics::__ClassInit();
		type_002A = Statics::javaToCppClass(type_002A);
		simpleType_003C = this->cppClass->simplifyType(type_002A);
		temp_0043 = new StringBuilder(createString("temp_"));
		Statics::__ClassInit();
		tempName_0056 = temp_0043->append(Statics::hexString(instruction->address, 4))->toString();
		temp_005F = new StringBuilder(createString("Pointer<JavaArray<"));
		source->liprintln(2, temp_005F->append(simpleType_003C)->append(createString(">> "))->append(tempName_0056)->append(createString(";"))->toString());
		String::__ClassInit();
		temp_0088 = new StringBuilder(String::valueOf(tempName_0056.getValue()));
		source->iprintln(temp_0088->append(createString(" = new JavaArray<"))->append(simpleType_003C)->append(createString(">("))->append(length_0024)->append(createString(");"))->toString());
		temp_00B4 = new StringBuilder(createString("JavaArray<"));
		newEntry_00D1 = temp_00B4->append(simpleType_003C)->append(createString(">"))->append(createString("\t"))->append(tempName_0056)->toString();
		this->stack->push(newEntry_00D1.getValue());
		return;
	}

	void CppExecutionContext::generateARETURN(Pointer<IndentedOutputStream> source, Pointer<InstructionARETURN> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> returnType_004C;
		Pointer<String> conversion_006F;
		Pointer<String> cast_0074;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_0030;
		Pointer<StringBuilder> temp_009E;
		Pointer<StringBuilder> temp_00B8;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		if (!(topOfStack_0010->get(0)->equals(createString("String"))))
			goto L0043;
		if (!(topOfStack_0010->get(1)->startsWith(createString("\""))))
			goto L0043;
		temp_0030 = new StringBuilder(createString("createString("));
		topOfStack_0010->assign(1, temp_0030->append(topOfStack_0010->get(1))->append(createString(")"))->toString());
	L0043: //
		Statics::__ClassInit();
		returnType_004C = Statics::parseJavaReturnType(this->type);
		returnType_004C = this->cppClass->simplifyType(returnType_004C);
		Statics::__ClassInit();
		Statics::Check(source, this->cppClass->isAssignable(topOfStack_0010->get(0), returnType_004C), createString("ARETURN: Type mismatch"));
		conversion_006F = createString("");
		cast_0074 = createString("");
		if (this->cppClass->isAssignable(topOfStack_0010->get(0), returnType_004C))
			goto L0088;
		conversion_006F = createString(".getValue()");
	L0088: //
		if (!(topOfStack_0010->get(1)->equals(createString("nullptr"))))
			goto L00B0;
		conversion_006F = createString("");
		temp_009E = new StringBuilder(createString("("));
		cast_0074 = temp_009E->append(returnType_004C)->append(createString("*)"))->toString();
	L00B0: //
		temp_00B8 = new StringBuilder(createString("return "));
		source->iprintln(temp_00B8->append(cast_0074)->append(topOfStack_0010->get(1))->append(conversion_006F)->append(createString(";"))->toString());
		return;
	}

	void CppExecutionContext::generateARRAYLENGTH(Pointer<IndentedOutputStream> source, Pointer<InstructionARRAYLENGTH> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		bool isArray_001B = false;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_003C;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		isArray_001B = topOfStack_0010->get(0)->startsWith(createString("JavaArray<"));
		isArray_001B = (isArray_001B) | (topOfStack_0010->get(0)->startsWith(createString("JavaRawArray<")));
		Statics::__ClassInit();
		Statics::Assert(isArray_001B, createString("Top of stack is not an array"));
		temp_003C = new StringBuilder(createString("int\t"));
		this->stack->push(temp_003C->append(topOfStack_0010->get(1))->append(createString("->length"))->toString().getValue());
		return;
	}

	void CppExecutionContext::generateASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionASTORE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		int index_0005 = 0;
		Pointer<LocalVariable> local_0032;
		Pointer<JavaArray<String>> topOfStack_0043;
		Pointer<String> sourceType_00EA;
		Pointer<String> localType_00F8;
		Pointer<String> temp_0039;
		Pointer<StringBuilder> temp_0066;
		Pointer<StringBuilder> temp_009E;
		Pointer<StringBuilder> temp_00C0;
		Pointer<StringBuilder> temp_0137;
		Pointer<StringBuilder> temp_0159;
		Pointer<StringBuilder> temp_0191;
		Pointer<StringBuilder> temp_01DC;
		Pointer<StringBuilder> temp_0208;
		index_0005 = instruction->getIndex();
		Statics::__ClassInit();
		Statics::Assert(((((index_0005) >= 0) ? (1) : (0))) != 0, createString("Local index out of range"));
		Statics::__ClassInit();
		Statics::Assert(((((index_0005) < (this->maxLocals)) ? (1) : (0))) != 0, createString("Local index out of range"));
		local_0032 = this->locals->get(index_0005, instruction.getValue());
		temp_0039 = (String*)((this->stack->pop()).getValue());
		temp_0039->checkCast(String::__thisClassStatic);
		topOfStack_0043 = (JavaArray<String>*)(temp_0039->split(createString("[\t]")).getValue());
		if (!(topOfStack_0043->get(0)->equals(createString("String"))))
			goto L007A;
		if (!(topOfStack_0043->get(1)->startsWith(createString("\""))))
			goto L007A;
		temp_0066 = new StringBuilder(createString("createString("));
		topOfStack_0043->assign(1, temp_0066->append(topOfStack_0043->get(1))->append(createString(")"))->toString());
	L007A: //
		if ((local_0032).getValue() != nullptr)
			goto L00DD;
		local_0032 = this->locals->set(index_0005, topOfStack_0043->get(0), instruction->address);
		String::__ClassInit();
		temp_009E = new StringBuilder(String::valueOf(topOfStack_0043->get(0).getValue()));
		topOfStack_0043->assign(0, temp_009E->append(this->addTemplateParameters(topOfStack_0043->get(0)))->toString());
		Statics::__ClassInit();
		String::__ClassInit();
		temp_00C0 = new StringBuilder(String::valueOf(Statics::addPointerIfNeeded(topOfStack_0043->get(0)).getValue()));
		source->liprintln(2, temp_00C0->append(createString(" "))->append(local_0032->getName())->append(createString(";"))->toString());
	L00DD: //
		sourceType_00EA = this->cppClass->simplifyType(topOfStack_0043->get(0));
		localType_00F8 = this->cppClass->simplifyType(local_0032->getType());
		if (sourceType_00EA->equals(localType_00F8.getValue()))
			goto L017C;
		if ((local_0032->endPc) != (65535))
			goto L017C;
		local_0032->endPc = (instruction->address) - (1);
		local_0032 = this->locals->set(index_0005, topOfStack_0043->get(0), instruction->address);
		String::__ClassInit();
		temp_0137 = new StringBuilder(String::valueOf(topOfStack_0043->get(0).getValue()));
		topOfStack_0043->assign(0, temp_0137->append(this->addTemplateParameters(topOfStack_0043->get(0)))->toString());
		Statics::__ClassInit();
		String::__ClassInit();
		temp_0159 = new StringBuilder(String::valueOf(Statics::addPointerIfNeeded(topOfStack_0043->get(0)).getValue()));
		source->liprintln(2, temp_0159->append(createString(" "))->append(local_0032->getName())->append(createString(";"))->toString());
		localType_00F8 = topOfStack_0043->get(0);
	L017C: //
		Statics::__ClassInit();
		if (!(Statics::isTemplate(localType_00F8)))
			goto L01BB;
		String::__ClassInit();
		temp_0191 = new StringBuilder(String::valueOf(local_0032->getName().getValue()));
		source->iprintln(temp_0191->append(createString(" = ("))->append(localType_00F8)->append(createString("*)("))->append(topOfStack_0043->get(1))->append(createString(".getValue());"))->toString());
		goto L022F;
	L01BB: //
		if (sourceType_00EA->equals(localType_00F8.getValue()))
			goto L01CF;
		if (!(sourceType_00EA->equals(createString("nullptr"))))
			goto L01FB;
	L01CF: //
		String::__ClassInit();
		temp_01DC = new StringBuilder(String::valueOf(local_0032->getName().getValue()));
		source->iprintln(temp_01DC->append(createString(" = "))->append(topOfStack_0043->get(1))->append(createString(";"))->toString());
		goto L022F;
	L01FB: //
		String::__ClassInit();
		temp_0208 = new StringBuilder(String::valueOf(local_0032->getName().getValue()));
		source->iprintln(temp_0208->append(createString(" = ("))->append(localType_00F8)->append(createString("*)("))->append(topOfStack_0043->get(1))->append(createString(".getValue());"))->toString());
	L022F: //
		return;
	}

	void CppExecutionContext::generateATHROW(Pointer<IndentedOutputStream> source, Pointer<InstructionATHROW> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_002B;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(this->cppClass->isAssignable(topOfStack_0010->get(0), createString("java::lang::Exception")), createString("ATHROW: Not an exception thrown"));
		temp_002B = new StringBuilder(createString("throw "));
		source->iprintln(temp_002B->append(topOfStack_0010->get(1))->append(createString(";"))->toString());
		return;
	}

	void CppExecutionContext::generateBALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionBALOAD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> index_0010;
		Pointer<JavaArray<String>> array_0021;
		bool isArray_002D = false;
		Pointer<String> arrayElementType_005C;
		Pointer<String> newEntry_008B;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_0065;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		index_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		array_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		isArray_002D = array_0021->get(0)->equals(createString("JavaRawArray<bool>"));
		isArray_002D = (isArray_002D) | (array_0021->get(0)->equals(createString("JavaRawArray<byte>")));
		Statics::__ClassInit();
		Statics::Assert(isArray_002D, createString("BALOAD: Array of bool or byte expected"));
		Statics::__ClassInit();
		Statics::Assert(index_0010->get(0)->equals(createString("int")), createString("BALOAD: Integer index expected"));
		Statics::__ClassInit();
		arrayElementType_005C = Statics::removeJavaArray(array_0021->get(0));
		String::__ClassInit();
		temp_0065 = new StringBuilder(String::valueOf(arrayElementType_005C.getValue()));
		newEntry_008B = temp_0065->append(createString("\t"))->append(array_0021->get(1))->append(createString("->get("))->append(index_0010->get(1))->append(createString(")"))->toString();
		this->stack->push(newEntry_008B.getValue());
		return;
	}

	void CppExecutionContext::generateBASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionBASTORE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> value_0010;
		Pointer<JavaArray<String>> index_0021;
		Pointer<JavaArray<String>> array_0032;
		bool isArray_003E = false;
		Pointer<String> arrayElementType_006E;
		bool isType_0078 = false;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<String> temp_0028;
		Pointer<StringBuilder> temp_00A0;
		Pointer<StringBuilder> temp_00BF;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		value_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		index_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		temp_0028 = (String*)((this->stack->pop()).getValue());
		temp_0028->checkCast(String::__thisClassStatic);
		array_0032 = (JavaArray<String>*)(temp_0028->split(createString("[\t]")).getValue());
		isArray_003E = array_0032->get(0)->equals(createString("JavaRawArray<bool>"));
		isArray_003E = (isArray_003E) | (array_0032->get(0)->equals(createString("JavaRawArray<byte>")));
		Statics::__ClassInit();
		Statics::Assert(isArray_003E, createString("BASTORE: Array of bool or byte expected"));
		Statics::__ClassInit();
		Statics::Assert(index_0021->get(0)->equals(createString("int")), createString("BASTORE: Integer index expected"));
		Statics::__ClassInit();
		arrayElementType_006E = Statics::removeJavaArray(array_0032->get(0));
		isType_0078 = value_0010->get(0)->equals(arrayElementType_006E.getValue());
		isType_0078 = (isType_0078) | (value_0010->get(0)->equals(createString("int")));
		Statics::__ClassInit();
		Statics::Assert(isType_0078, createString("BASTORE: Value does not match JavaRawArray type"));
		if (!(arrayElementType_006E->equals(createString("bool"))))
			goto L00B3;
		temp_00A0 = new StringBuilder(createString("("));
		value_0010->assign(1, temp_00A0->append(value_0010->get(1))->append(createString(") & 1"))->toString());
	L00B3: //
		String::__ClassInit();
		temp_00BF = new StringBuilder(String::valueOf(array_0032->get(1).getValue()));
		source->iprintln(temp_00BF->append(createString("->assign("))->append(index_0021->get(1))->append(createString(", "))->append(value_0010->get(1))->append(createString(");"))->toString());
		return;
	}

	void CppExecutionContext::generateBinaryOp(Pointer<IndentedOutputStream> source, Pointer<Instruction> instruction, Pointer<String> type, Pointer<String> op)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> insnType_000E;
		Pointer<JavaArray<String>> right_001F;
		Pointer<JavaArray<String>> left_0030;
		Pointer<JavaArray<String>> types_0039;
		bool isType_003C = false;
		Pointer<String> finalType_0041;
		Pointer<String> thisType_0056;
		bool isThisType_0061 = false;
		Pointer<String> newEntry_00ED;
		Pointer<String> temp_0015;
		Pointer<String> temp_0026;
		Pointer<JavaArray<String>> local_0044;
		int local_0047 = 0;
		int local_004A = 0;
		Pointer<StringBuilder> temp_0094;
		Pointer<StringBuilder> temp_00B6;
		insnType_000E = instruction->getClass()->getSimpleName()->substring(8);
		temp_0015 = (String*)((this->stack->pop()).getValue());
		temp_0015->checkCast(String::__thisClassStatic);
		right_001F = (JavaArray<String>*)(temp_0015->split(createString("[\t]")).getValue());
		temp_0026 = (String*)((this->stack->pop()).getValue());
		temp_0026->checkCast(String::__thisClassStatic);
		left_0030 = (JavaArray<String>*)(temp_0026->split(createString("[\t]")).getValue());
		types_0039 = (JavaArray<String>*)(type->split(createString("[|]")).getValue());
		isType_003C = 0;
		finalType_0041 = createString("");
		local_0044 = (JavaArray<String>*)(types_0039.getValue());
		local_0047 = types_0039->length;
		local_004A = 0;
		goto L0082;
	L004F: //
		thisType_0056 = local_0044->get(local_004A);
		isThisType_0061 = left_0030->get(0)->equals(thisType_0056.getValue());
		isThisType_0061 = (isThisType_0061) & (right_001F->get(0)->equals(thisType_0056.getValue()));
		isType_003C = (isType_003C) | (isThisType_0061);
		if (!(isThisType_0061))
			goto L007F;
		finalType_0041 = thisType_0056;
	L007F: //
		local_004A += 1;
	L0082: //
		if ((local_004A) < (local_0047))
			goto L004F;
		String::__ClassInit();
		temp_0094 = new StringBuilder(String::valueOf(insnType_000E.getValue()));
		Statics::__ClassInit();
		Statics::Assert(isType_003C, temp_0094->append(createString(": Left and right \'"))->append(type)->append(createString("\' type expected"))->toString());
		String::__ClassInit();
		temp_00B6 = new StringBuilder(String::valueOf(finalType_0041.getValue()));
		newEntry_00ED = temp_00B6->append(createString("\t"))->append(createString("("))->append(left_0030->get(1))->append(createString(") "))->append(op)->append(createString(" ("))->append(right_001F->get(1))->append(createString(")"))->toString();
		this->stack->push(newEntry_00ED.getValue());
		return;
	}

	void CppExecutionContext::generateBIPUSH(Pointer<IndentedOutputStream> source, Pointer<InstructionBIPUSH> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> stackEntry_0015;
		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("int\t"));
		stackEntry_0015 = temp_0007->append(instruction->getValue())->toString();
		this->stack->push(stackEntry_0015.getValue());
		return;
	}

	void CppExecutionContext::generateCALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionCALOAD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateCASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionCASTORE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateCHECKCAST(Pointer<IndentedOutputStream> source, Pointer<InstructionCHECKCAST> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> localName_002A;
		Pointer<String> className_0033;
		bool raw_0050 = false;
		Pointer<String> array_0060;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_0017;
		Pointer<StringBuilder> temp_0069;
		Pointer<StringBuilder> temp_00A1;
		Pointer<StringBuilder> temp_00CA;
		Pointer<StringBuilder> temp_00FA;
		Pointer<StringBuilder> temp_0121;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = new StringBuilder(createString("temp_"));
		Statics::__ClassInit();
		localName_002A = temp_0017->append(Statics::hexString(instruction->address, 4))->toString();
		Statics::__ClassInit();
		className_0033 = Statics::javaToCppClass(instruction->getClassName());
		if (!(className_0033->endsWith(createString("[]"))))
			goto L008D;
		raw_0050 = (((className_0033->indexOf(createString("::"))) == (-1)) ? (1) : (0));
		array_0060 = ((raw_0050) ? (((Pointer<String>) new String("JavaRawArray"))) : (((Pointer<String>) new String("JavaArray"))));
		String::__ClassInit();
		temp_0069 = new StringBuilder(String::valueOf(array_0060.getValue()));
		className_0033 = temp_0069->append(createString("<"))->append(className_0033->substring(0, (className_0033->length()) - (2)))->append(createString(">"))->toString();
	L008D: //
		className_0033 = this->cppClass->simplifyType(className_0033);
		temp_00A1 = new StringBuilder(createString("Pointer<"));
		source->liprintln(2, temp_00A1->append(className_0033)->append(createString("> "))->append(localName_002A)->append(createString(";"))->toString());
		String::__ClassInit();
		temp_00CA = new StringBuilder(String::valueOf(localName_002A.getValue()));
		source->iprintln(temp_00CA->append(createString(" = ("))->append(className_0033)->append(createString("*)(("))->append(topOfStack_0010->get(1))->append(createString(").getValue());"))->toString());
		String::__ClassInit();
		temp_00FA = new StringBuilder(String::valueOf(localName_002A.getValue()));
		source->iprintln(temp_00FA->append(createString("->checkCast("))->append(className_0033)->append(createString("::__thisClassStatic);"))->toString());
		String::__ClassInit();
		temp_0121 = new StringBuilder(String::valueOf(className_0033.getValue()));
		this->stack->push(temp_0121->append(createString("\t"))->append(localName_002A)->toString().getValue());
		return;
	}

	void CppExecutionContext::generateConversion(Pointer<Instruction> instruction, Pointer<String> typeFrom, Pointer<String> typeTo)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> instructionName_000E;
		Pointer<JavaArray<String>> value_001F;
		Pointer<String> newEntry_0087;
		Pointer<String> temp_0015;
		Pointer<StringBuilder> temp_0030;
		Pointer<StringBuilder> temp_005E;
		instructionName_000E = instruction->getClass()->getSimpleName()->substring(8);
		temp_0015 = (String*)((this->stack->pop()).getValue());
		temp_0015->checkCast(String::__thisClassStatic);
		value_001F = (JavaArray<String>*)(temp_0015->split(createString("[\t]")).getValue());
		String::__ClassInit();
		temp_0030 = new StringBuilder(String::valueOf(instructionName_000E.getValue()));
		Statics::__ClassInit();
		Statics::Assert(value_001F->get(0)->equals(typeFrom.getValue()), temp_0030->append(createString(": Bad \'from\' type "))->append(value_001F->get(0))->append(createString(", "))->append(typeFrom)->append(createString(" expected"))->toString());
		String::__ClassInit();
		temp_005E = new StringBuilder(String::valueOf(typeTo.getValue()));
		newEntry_0087 = temp_005E->append(createString("\t"))->append(createString("("))->append(typeTo)->append(createString(") ("))->append(value_001F->get(1))->append(createString(")"))->toString();
		this->stack->push(newEntry_0087.getValue());
		return;
	}

	void CppExecutionContext::generateD2F(Pointer<IndentedOutputStream> source, Pointer<InstructionD2F> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("double"), createString("float"));
		return;
	}

	void CppExecutionContext::generateD2I(Pointer<IndentedOutputStream> source, Pointer<InstructionD2I> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("double"), createString("int"));
		return;
	}

	void CppExecutionContext::generateD2L(Pointer<IndentedOutputStream> source, Pointer<InstructionD2L> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("double"), createString("INT64"));
		return;
	}

	void CppExecutionContext::generateDADD(Pointer<IndentedOutputStream> source, Pointer<InstructionDADD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("double"), createString("+"));
		return;
	}

	void CppExecutionContext::generateDALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionDALOAD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateDASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionDASTORE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateDCMPG(Pointer<IndentedOutputStream> source, Pointer<InstructionDCMPG> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateDCMPL(Pointer<IndentedOutputStream> source, Pointer<InstructionDCMPL> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateDCONST(Pointer<IndentedOutputStream> source, Pointer<InstructionDCONST> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> newEntry_0015;
		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("double\t"));
		newEntry_0015 = temp_0007->append(instruction->getValue())->toString();
		this->stack->push(newEntry_0015.getValue());
		return;
	}

	void CppExecutionContext::generateDDIV(Pointer<IndentedOutputStream> source, Pointer<InstructionDDIV> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("double"), createString("/"));
		return;
	}

	void CppExecutionContext::generateDLOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionDLOAD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateXLOAD(source, instruction.getValue(), createString("double"));
		return;
	}

	void CppExecutionContext::generateDMUL(Pointer<IndentedOutputStream> source, Pointer<InstructionDMUL> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("double"), createString("*"));
		return;
	}

	void CppExecutionContext::generateDNEG(Pointer<IndentedOutputStream> source, Pointer<InstructionDNEG> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateDREM(Pointer<IndentedOutputStream> source, Pointer<InstructionDREM> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("double"), createString("%"));
		return;
	}

	void CppExecutionContext::generateDRETURN(Pointer<IndentedOutputStream> source, Pointer<InstructionDRETURN> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateXRETURN(source, instruction.getValue(), createString("double"));
		return;
	}

	void CppExecutionContext::generateDSTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionDSTORE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateXSTORE(source, instruction.getValue(), createString("double"));
		return;
	}

	void CppExecutionContext::generateDSUB(Pointer<IndentedOutputStream> source, Pointer<InstructionDSUB> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("double"), createString("-"));
		return;
	}

	void CppExecutionContext::generateDUP(Pointer<IndentedOutputStream> source, Pointer<InstructionDUP> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> top_000B;
		Pointer<String> temp_0007;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		top_000B = temp_0007;
		this->stack->push(top_000B.getValue());
		this->stack->push(top_000B.getValue());
		return;
	}

	void CppExecutionContext::generateDUP_X1(Pointer<IndentedOutputStream> source, Pointer<InstructionDUP_X1> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> value1_000B;
		Pointer<String> value2_0017;
		Pointer<String> temp_0007;
		Pointer<String> temp_0012;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		value1_000B = temp_0007;
		temp_0012 = (String*)((this->stack->pop()).getValue());
		temp_0012->checkCast(String::__thisClassStatic);
		value2_0017 = temp_0012;
		this->stack->push(value1_000B.getValue());
		this->stack->push(value2_0017.getValue());
		this->stack->push(value1_000B.getValue());
		return;
	}

	void CppExecutionContext::generateDUP_X2(Pointer<IndentedOutputStream> source, Pointer<InstructionDUP_X2> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateDUP2(Pointer<IndentedOutputStream> source, Pointer<InstructionDUP2> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> value1_000B;
		Pointer<String> value2_0017;
		Pointer<String> temp_0007;
		Pointer<String> temp_0012;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		value1_000B = temp_0007;
		temp_0012 = (String*)((this->stack->pop()).getValue());
		temp_0012->checkCast(String::__thisClassStatic);
		value2_0017 = temp_0012;
		this->stack->push(value2_0017.getValue());
		this->stack->push(value1_000B.getValue());
		this->stack->push(value2_0017.getValue());
		this->stack->push(value1_000B.getValue());
		return;
	}

	void CppExecutionContext::generateDUP2_X1(Pointer<IndentedOutputStream> source, Pointer<InstructionDUP2_X1> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateDUP2_X2(Pointer<IndentedOutputStream> source, Pointer<InstructionDUP2_X2> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateF2D(Pointer<IndentedOutputStream> source, Pointer<InstructionF2D> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("float"), createString("double"));
		return;
	}

	void CppExecutionContext::generateF2I(Pointer<IndentedOutputStream> source, Pointer<InstructionF2I> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("float"), createString("int"));
		return;
	}

	void CppExecutionContext::generateF2L(Pointer<IndentedOutputStream> source, Pointer<InstructionF2L> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("float"), createString("INT64"));
		return;
	}

	void CppExecutionContext::generateFADD(Pointer<IndentedOutputStream> source, Pointer<InstructionFADD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("float"), createString("+"));
		return;
	}

	void CppExecutionContext::generateFALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionFALOAD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateFASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionFASTORE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateFCMPG(Pointer<IndentedOutputStream> source, Pointer<InstructionFCMPG> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateFCMPL(Pointer<IndentedOutputStream> source, Pointer<InstructionFCMPL> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateFCONST(Pointer<IndentedOutputStream> source, Pointer<InstructionFCONST> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateFDIV(Pointer<IndentedOutputStream> source, Pointer<InstructionFDIV> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("float"), createString("/"));
		return;
	}

	void CppExecutionContext::generateFLOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionFLOAD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateXLOAD(source, instruction.getValue(), createString("float"));
		return;
	}

	void CppExecutionContext::generateFMUL(Pointer<IndentedOutputStream> source, Pointer<InstructionFMUL> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("float"), createString("*"));
		return;
	}

	void CppExecutionContext::generateFNEG(Pointer<IndentedOutputStream> source, Pointer<InstructionFNEG> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateFREM(Pointer<IndentedOutputStream> source, Pointer<InstructionFREM> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("float"), createString("%"));
		return;
	}

	void CppExecutionContext::generateFRETURN(Pointer<IndentedOutputStream> source, Pointer<InstructionFRETURN> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateXRETURN(source, instruction.getValue(), createString("float"));
		return;
	}

	void CppExecutionContext::generateFSTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionFSTORE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateXSTORE(source, instruction.getValue(), createString("float"));
		return;
	}

	void CppExecutionContext::generateFSUB(Pointer<IndentedOutputStream> source, Pointer<InstructionFSUB> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("float"), createString("-"));
		return;
	}

	void CppExecutionContext::generateGETFIELD(Pointer<IndentedOutputStream> source, Pointer<InstructionGETFIELD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> object_0010;
		Pointer<ClassFile> javaClass_0019;
		Pointer<String> fieldName_001F;
		Pointer<String> fieldType_0028;
		Pointer<String> newEntry_0069;
		Pointer<String> temp_0007;
		Pointer<JavaTypeConverter> temp_002F;
		Pointer<StringBuilder> temp_004B;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		object_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		javaClass_0019 = this->findClassByName(object_0010->get(0));
		fieldName_001F = instruction->getFieldName();
		fieldType_0028 = javaClass_0019->getFieldType(fieldName_001F);
		temp_002F = new JavaTypeConverter(fieldType_0028, true);
		fieldType_0028 = temp_002F->getCppType();
		fieldType_0028 = this->cppClass->simplifyType(fieldType_0028);
		String::__ClassInit();
		temp_004B = new StringBuilder(String::valueOf(fieldType_0028.getValue()));
		newEntry_0069 = temp_004B->append(createString("\t"))->append(object_0010->get(1))->append(createString("->"))->append(fieldName_001F)->toString();
		this->stack->push(newEntry_0069.getValue());
		return;
	}

	void CppExecutionContext::generateGETSTATIC(Pointer<IndentedOutputStream> source, Pointer<InstructionGETSTATIC> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0010;
		Pointer<String> fieldName_001F;
		Pointer<String> fieldType_0030;
		Pointer<String> newEntry_0066;
		Pointer<String> newEntry_00AC;
		Pointer<JavaTypeConverter> temp_0009;
		Pointer<JavaTypeConverter> temp_0028;
		Pointer<StringBuilder> temp_004B;
		Pointer<StringBuilder> temp_0079;
		Pointer<StringBuilder> temp_0091;
		temp_0009 = new JavaTypeConverter(instruction->getClassName(), true);
		className_0010 = temp_0009->getCppType();
		className_0010 = this->cppClass->simplifyType(className_0010);
		fieldName_001F = instruction->getFieldName();
		temp_0028 = new JavaTypeConverter(instruction->getFieldType(), true);
		fieldType_0030 = temp_0028->getCppType();
		fieldType_0030 = this->cppClass->simplifyType(fieldType_0030);
		if (!(this->isStaticConstructor))
			goto L0070;
		String::__ClassInit();
		temp_004B = new StringBuilder(String::valueOf(fieldType_0030.getValue()));
		newEntry_0066 = temp_004B->append(createString("\t"))->append(className_0010)->append(createString("::"))->append(fieldName_001F)->toString();
		Statics::__ClassInit();
		Statics::Assert(false, createString(""));
		goto L00AC;
	L0070: //
		String::__ClassInit();
		temp_0079 = new StringBuilder(String::valueOf(className_0010.getValue()));
		source->iprintln(temp_0079->append(createString("::__ClassInit();"))->toString());
		String::__ClassInit();
		temp_0091 = new StringBuilder(String::valueOf(fieldType_0030.getValue()));
		newEntry_00AC = temp_0091->append(createString("\t"))->append(className_0010)->append(createString("::"))->append(fieldName_001F)->toString();
	L00AC: //
		this->stack->push(newEntry_00AC.getValue());
		return;
	}

	void CppExecutionContext::generateGOTO(Pointer<IndentedOutputStream> source, Pointer<InstructionGOTO> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<TernaryOperator> ternary_0045;
		Pointer<StringBuilder> temp_0017;
		Pointer<TernaryOperator> temp_0041;
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L0030;
		temp_0017 = new StringBuilder(createString("goto "));
		source->iprintln(temp_0017->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L0063;
	L0030: //
		if ((this->ternaryStack->size()) <= 0)
			goto L005E;
		temp_0041 = (TernaryOperator*)((this->ternaryStack->firstElement()).getValue());
		temp_0041->checkCast(TernaryOperator::__thisClassStatic);
		ternary_0045 = temp_0041;
		Statics::__ClassInit();
		Statics::Assert(((((instruction->address) == (ternary_0045->endOfTruePath)) ? (1) : (0))) != 0, createString("GOTO found in wrong place"));
		goto L0063;
	L005E: //
		this->notSupported(instruction.getValue());
	L0063: //
		return;
	}

	void CppExecutionContext::generateGOTO_W(Pointer<IndentedOutputStream> source, Pointer<InstructionGOTO_W> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateI2B(Pointer<IndentedOutputStream> source, Pointer<InstructionI2B> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("int"), createString("bool"));
		return;
	}

	void CppExecutionContext::generateI2C(Pointer<IndentedOutputStream> source, Pointer<InstructionI2C> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("int"), createString("char"));
		return;
	}

	void CppExecutionContext::generateI2D(Pointer<IndentedOutputStream> source, Pointer<InstructionI2D> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("int"), createString("double"));
		return;
	}

	void CppExecutionContext::generateI2F(Pointer<IndentedOutputStream> source, Pointer<InstructionI2F> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("int"), createString("float"));
		return;
	}

	void CppExecutionContext::generateI2L(Pointer<IndentedOutputStream> source, Pointer<InstructionI2L> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("int"), createString("INT64"));
		return;
	}

	void CppExecutionContext::generateI2S(Pointer<IndentedOutputStream> source, Pointer<InstructionI2S> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("int"), createString("short"));
		return;
	}

	void CppExecutionContext::generateIADD(Pointer<IndentedOutputStream> source, Pointer<InstructionIADD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("int"), createString("+"));
		return;
	}

	void CppExecutionContext::generateIALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionIALOAD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> index_0010;
		Pointer<JavaArray<String>> array_0021;
		Pointer<String> newEntry_0068;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_0047;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		index_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		array_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(index_0010->get(0)->equals(createString("int")), createString("IALOAD: Integer index expected"));
		Statics::__ClassInit();
		Statics::Assert(array_0021->get(0)->equals(createString("JavaRawArray<int>")), createString("IALOAD: Integer array expected"));
		temp_0047 = new StringBuilder(createString("int\t"));
		newEntry_0068 = temp_0047->append(array_0021->get(1))->append(createString("->get("))->append(index_0010->get(1))->append(createString(")"))->toString();
		this->stack->push(newEntry_0068.getValue());
		return;
	}

	void CppExecutionContext::generateIAND(Pointer<IndentedOutputStream> source, Pointer<InstructionIAND> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("int|bool"), createString("&"));
		return;
	}

	void CppExecutionContext::generateIASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionIASTORE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> value_0010;
		Pointer<JavaArray<String>> index_0021;
		Pointer<JavaArray<String>> array_0032;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<String> temp_0028;
		Pointer<StringBuilder> temp_005E;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		value_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		index_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		temp_0028 = (String*)((this->stack->pop()).getValue());
		temp_0028->checkCast(String::__thisClassStatic);
		array_0032 = (JavaArray<String>*)(temp_0028->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(index_0021->get(0)->equals(createString("int")), createString("IASTORE: Integer index expected"));
		Statics::__ClassInit();
		Statics::Assert(array_0032->get(0)->equals(createString("JavaRawArray<int>")), createString("IASTORE: Integer array expected"));
		String::__ClassInit();
		temp_005E = new StringBuilder(String::valueOf(array_0032->get(1).getValue()));
		source->iprintln(temp_005E->append(createString("->assign("))->append(index_0021->get(1))->append(createString(", "))->append(value_0010->get(1))->append(createString(");"))->toString());
		return;
	}

	void CppExecutionContext::generateICONST(Pointer<IndentedOutputStream> source, Pointer<InstructionICONST> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> newEntry_0015;
		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("int\t"));
		newEntry_0015 = temp_0007->append(instruction->getValue())->toString();
		this->stack->push(newEntry_0015.getValue());
		return;
	}

	void CppExecutionContext::generateIDIV(Pointer<IndentedOutputStream> source, Pointer<InstructionIDIV> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("int"), createString("/"));
		return;
	}

	void CppExecutionContext::generateIF_ACMPEQ(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ACMPEQ> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> right_0010;
		Pointer<JavaArray<String>> left_0021;
		Pointer<String> condition_00A1;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_0038;
		Pointer<StringBuilder> temp_0061;
		Pointer<StringBuilder> temp_0081;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		right_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		left_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L007A;
		temp_0038 = new StringBuilder(createString("if (("));
		source->iprintln(temp_0038->append(left_0021->get(1))->append(createString(") == ("))->append(right_0010->get(1))->append(createString("))"))->toString());
		temp_0061 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_0061->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L00A8;
	L007A: //
		temp_0081 = new StringBuilder(createString("(("));
		condition_00A1 = temp_0081->append(left_0021->get(1))->append(createString(") != ("))->append(right_0010->get(1))->append(createString("))"))->toString();
		this->generateTernary(instruction.getValue(), condition_00A1);
	L00A8: //
		return;
	}

	void CppExecutionContext::generateIF_ACMPNE(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ACMPNE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> right_0010;
		Pointer<JavaArray<String>> left_0021;
		Pointer<String> condition_00A1;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_0038;
		Pointer<StringBuilder> temp_0061;
		Pointer<StringBuilder> temp_0081;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		right_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		left_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L007A;
		temp_0038 = new StringBuilder(createString("if (("));
		source->iprintln(temp_0038->append(left_0021->get(1))->append(createString(") != ("))->append(right_0010->get(1))->append(createString("))"))->toString());
		temp_0061 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_0061->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L00A8;
	L007A: //
		temp_0081 = new StringBuilder(createString("(("));
		condition_00A1 = temp_0081->append(left_0021->get(1))->append(createString(") == ("))->append(right_0010->get(1))->append(createString("))"))->toString();
		this->generateTernary(instruction.getValue(), condition_00A1);
	L00A8: //
		return;
	}

	void CppExecutionContext::generateIF_ICMPEQ(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ICMPEQ> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> right_0010;
		Pointer<JavaArray<String>> left_0021;
		bool isLeft_002D = false;
		bool isRight_0047 = false;
		Pointer<String> condition_00E5;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_007C;
		Pointer<StringBuilder> temp_00A5;
		Pointer<StringBuilder> temp_00C5;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		right_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		left_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		isLeft_002D = left_0021->get(0)->equals(createString("int"));
		isLeft_002D = (isLeft_002D) | (left_0021->get(0)->equals(createString("char")));
		isRight_0047 = right_0010->get(0)->equals(createString("int"));
		isRight_0047 = (isRight_0047) | (right_0010->get(0)->equals(createString("char")));
		Statics::__ClassInit();
		Statics::Assert(isLeft_002D, createString("IF_ICMPEQ: Integer or char expected"));
		Statics::__ClassInit();
		Statics::Assert(isRight_0047, createString("IF_ICMPEQ: Integer or char expected"));
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L00BE;
		temp_007C = new StringBuilder(createString("if (("));
		source->iprintln(temp_007C->append(left_0021->get(1))->append(createString(") == ("))->append(right_0010->get(1))->append(createString("))"))->toString());
		temp_00A5 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_00A5->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L00EC;
	L00BE: //
		temp_00C5 = new StringBuilder(createString("(("));
		condition_00E5 = temp_00C5->append(left_0021->get(1))->append(createString(") != ("))->append(right_0010->get(1))->append(createString("))"))->toString();
		this->generateTernary(instruction.getValue(), condition_00E5);
	L00EC: //
		return;
	}

	void CppExecutionContext::generateIF_ICMPGE(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ICMPGE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> right_0010;
		Pointer<JavaArray<String>> left_0021;
		bool isLeft_002D = false;
		bool isRight_0047 = false;
		Pointer<String> condition_00E5;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_007C;
		Pointer<StringBuilder> temp_00A5;
		Pointer<StringBuilder> temp_00C5;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		right_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		left_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		isLeft_002D = left_0021->get(0)->equals(createString("int"));
		isLeft_002D = (isLeft_002D) | (left_0021->get(0)->equals(createString("char")));
		isRight_0047 = right_0010->get(0)->equals(createString("int"));
		isRight_0047 = (isRight_0047) | (right_0010->get(0)->equals(createString("char")));
		Statics::__ClassInit();
		Statics::Assert(isLeft_002D, createString("IF_ICMPGE: Integer or char expected"));
		Statics::__ClassInit();
		Statics::Assert(isRight_0047, createString("IF_ICMPGE: Integer or char expected"));
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L00BE;
		temp_007C = new StringBuilder(createString("if (("));
		source->iprintln(temp_007C->append(left_0021->get(1))->append(createString(") >= ("))->append(right_0010->get(1))->append(createString("))"))->toString());
		temp_00A5 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_00A5->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L00EC;
	L00BE: //
		temp_00C5 = new StringBuilder(createString("(("));
		condition_00E5 = temp_00C5->append(left_0021->get(1))->append(createString(") < ("))->append(right_0010->get(1))->append(createString("))"))->toString();
		this->generateTernary(instruction.getValue(), condition_00E5);
	L00EC: //
		return;
	}

	void CppExecutionContext::generateIF_ICMPGT(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ICMPGT> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> right_0010;
		Pointer<JavaArray<String>> left_0021;
		bool isLeft_002D = false;
		bool isRight_0047 = false;
		Pointer<String> condition_00E5;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_007C;
		Pointer<StringBuilder> temp_00A5;
		Pointer<StringBuilder> temp_00C5;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		right_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		left_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		isLeft_002D = left_0021->get(0)->equals(createString("int"));
		isLeft_002D = (isLeft_002D) | (left_0021->get(0)->equals(createString("char")));
		isRight_0047 = right_0010->get(0)->equals(createString("int"));
		isRight_0047 = (isRight_0047) | (right_0010->get(0)->equals(createString("char")));
		Statics::__ClassInit();
		Statics::Assert(isLeft_002D, createString("IF_ICMPGT: Integer or char expected"));
		Statics::__ClassInit();
		Statics::Assert(isRight_0047, createString("IF_ICMPGT: Integer or char expected"));
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L00BE;
		temp_007C = new StringBuilder(createString("if (("));
		source->iprintln(temp_007C->append(left_0021->get(1))->append(createString(") > ("))->append(right_0010->get(1))->append(createString("))"))->toString());
		temp_00A5 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_00A5->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L00EC;
	L00BE: //
		temp_00C5 = new StringBuilder(createString("(("));
		condition_00E5 = temp_00C5->append(left_0021->get(1))->append(createString(") <= ("))->append(right_0010->get(1))->append(createString("))"))->toString();
		this->generateTernary(instruction.getValue(), condition_00E5);
	L00EC: //
		return;
	}

	void CppExecutionContext::generateIF_ICMPLE(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ICMPLE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> right_0010;
		Pointer<JavaArray<String>> left_0021;
		bool isLeft_002D = false;
		bool isRight_0047 = false;
		Pointer<String> condition_00E5;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_007C;
		Pointer<StringBuilder> temp_00A5;
		Pointer<StringBuilder> temp_00C5;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		right_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		left_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		isLeft_002D = left_0021->get(0)->equals(createString("int"));
		isLeft_002D = (isLeft_002D) | (left_0021->get(0)->equals(createString("char")));
		isRight_0047 = right_0010->get(0)->equals(createString("int"));
		isRight_0047 = (isRight_0047) | (right_0010->get(0)->equals(createString("char")));
		Statics::__ClassInit();
		Statics::Assert(isLeft_002D, createString("IF_ICMPLE: Integer or char expected"));
		Statics::__ClassInit();
		Statics::Assert(isRight_0047, createString("IF_ICMPLE: Integer or char expected"));
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L00BE;
		temp_007C = new StringBuilder(createString("if (("));
		source->iprintln(temp_007C->append(left_0021->get(1))->append(createString(") <= ("))->append(right_0010->get(1))->append(createString("))"))->toString());
		temp_00A5 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_00A5->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L00EC;
	L00BE: //
		temp_00C5 = new StringBuilder(createString("(("));
		condition_00E5 = temp_00C5->append(left_0021->get(1))->append(createString(") > ("))->append(right_0010->get(1))->append(createString("))"))->toString();
		this->generateTernary(instruction.getValue(), condition_00E5);
	L00EC: //
		return;
	}

	void CppExecutionContext::generateIF_ICMPLT(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ICMPLT> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> right_0010;
		Pointer<JavaArray<String>> left_0021;
		bool isLeft_002D = false;
		bool isRight_0047 = false;
		Pointer<String> condition_00E5;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_007C;
		Pointer<StringBuilder> temp_00A5;
		Pointer<StringBuilder> temp_00C5;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		right_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		left_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		isLeft_002D = left_0021->get(0)->equals(createString("int"));
		isLeft_002D = (isLeft_002D) | (left_0021->get(0)->equals(createString("char")));
		isRight_0047 = right_0010->get(0)->equals(createString("int"));
		isRight_0047 = (isRight_0047) | (right_0010->get(0)->equals(createString("char")));
		Statics::__ClassInit();
		Statics::Assert(isLeft_002D, createString("IF_ICMPLT: Integer or char expected"));
		Statics::__ClassInit();
		Statics::Assert(isRight_0047, createString("IF_ICMPLT: Integer or char expected"));
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L00BE;
		temp_007C = new StringBuilder(createString("if (("));
		source->iprintln(temp_007C->append(left_0021->get(1))->append(createString(") < ("))->append(right_0010->get(1))->append(createString("))"))->toString());
		temp_00A5 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_00A5->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L00EC;
	L00BE: //
		temp_00C5 = new StringBuilder(createString("(("));
		condition_00E5 = temp_00C5->append(left_0021->get(1))->append(createString(") >= ("))->append(right_0010->get(1))->append(createString("))"))->toString();
		this->generateTernary(instruction.getValue(), condition_00E5);
	L00EC: //
		return;
	}

	void CppExecutionContext::generateIF_ICMPNE(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ICMPNE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> right_0010;
		Pointer<JavaArray<String>> left_0021;
		bool isLeft_002D = false;
		bool isRight_0047 = false;
		Pointer<String> condition_00E5;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_007C;
		Pointer<StringBuilder> temp_00A5;
		Pointer<StringBuilder> temp_00C5;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		right_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		left_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		isLeft_002D = left_0021->get(0)->equals(createString("int"));
		isLeft_002D = (isLeft_002D) | (left_0021->get(0)->equals(createString("char")));
		isRight_0047 = right_0010->get(0)->equals(createString("int"));
		isRight_0047 = (isRight_0047) | (right_0010->get(0)->equals(createString("char")));
		Statics::__ClassInit();
		Statics::Assert(isLeft_002D, createString("IF_ICMPNE: Integer or char expected"));
		Statics::__ClassInit();
		Statics::Assert(isRight_0047, createString("IF_ICMPNE: Integer or char expected"));
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L00BE;
		temp_007C = new StringBuilder(createString("if (("));
		source->iprintln(temp_007C->append(left_0021->get(1))->append(createString(") != ("))->append(right_0010->get(1))->append(createString("))"))->toString());
		temp_00A5 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_00A5->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L00EC;
	L00BE: //
		temp_00C5 = new StringBuilder(createString("(("));
		condition_00E5 = temp_00C5->append(left_0021->get(1))->append(createString(") == ("))->append(right_0010->get(1))->append(createString("))"))->toString();
		this->generateTernary(instruction.getValue(), condition_00E5);
	L00EC: //
		return;
	}

	void CppExecutionContext::generateIFEQ(Pointer<IndentedOutputStream> source, Pointer<InstructionIFEQ> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> condition_00B7;
		Pointer<String> condition_0127;
		Pointer<String> temp_0007;
		Pointer<String> local_0014;
		Pointer<StringBuilder> temp_0066;
		Pointer<StringBuilder> temp_0083;
		Pointer<StringBuilder> temp_00A3;
		Pointer<StringBuilder> temp_00D8;
		Pointer<StringBuilder> temp_00F4;
		Pointer<StringBuilder> temp_0113;
		Pointer<StringBuilder> temp_0139;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		local_0014 = topOfStack_0010->get(0);
		switch (topOfStack_0010->get(0)->hashCode())
		{
		case (int)0x000197EF:
			goto L0034;
		case (int)0x002E3AEA:
			goto L0042;
		default:
			goto L0131;
		}
	L0034: //
		if (local_0014->equals(createString("int")))
			goto L004F;
		goto L0131;
	L0042: //
		if (local_0014->equals(createString("bool")))
			goto L00C1;
		goto L0131;
	L004F: //
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L009C;
		temp_0066 = new StringBuilder(createString("if (("));
		source->iprintln(temp_0066->append(topOfStack_0010->get(1))->append(createString(") == 0)"))->toString());
		temp_0083 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_0083->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L0148;
	L009C: //
		temp_00A3 = new StringBuilder(createString("(("));
		condition_00B7 = temp_00A3->append(topOfStack_0010->get(1))->append(createString(") != 0)"))->toString();
		this->generateTernary(instruction.getValue(), condition_00B7);
		goto L0148;
	L00C1: //
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L010D;
		temp_00D8 = new StringBuilder(createString("if (!("));
		source->iprintln(temp_00D8->append(topOfStack_0010->get(1))->append(createString("))"))->toString());
		temp_00F4 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_00F4->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L0148;
	L010D: //
		temp_0113 = new StringBuilder(createString("("));
		condition_0127 = temp_0113->append(topOfStack_0010->get(1))->append(createString(")"))->toString();
		this->generateTernary(instruction.getValue(), condition_0127);
		goto L0148;
	L0131: //
		temp_0139 = new StringBuilder(createString("IFEQ: Unhandled operand type "));
		Statics::__ClassInit();
		Statics::Assert(false, temp_0139->append(topOfStack_0010->get(0))->toString());
	L0148: //
		return;
	}

	void CppExecutionContext::generateIFGE(Pointer<IndentedOutputStream> source, Pointer<InstructionIFGE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> temp_0007;
		Pointer<String> local_0014;
		Pointer<StringBuilder> temp_0051;
		Pointer<StringBuilder> temp_006E;
		Pointer<StringBuilder> temp_0097;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		local_0014 = topOfStack_0010->get(0);
		switch (topOfStack_0010->get(0)->hashCode())
		{
		case (int)0x000197EF:
			goto L002C;
		default:
			goto L008F;
		}
	L002C: //
		if (local_0014->equals(createString("int")))
			goto L003A;
		goto L008F;
	L003A: //
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L0087;
		temp_0051 = new StringBuilder(createString("if (("));
		source->iprintln(temp_0051->append(topOfStack_0010->get(1))->append(createString(") >= 0)"))->toString());
		temp_006E = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_006E->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L00A6;
	L0087: //
		this->notSupported(instruction.getValue());
		goto L00A6;
	L008F: //
		temp_0097 = new StringBuilder(createString("IFGE: Unhandled operand type "));
		Statics::__ClassInit();
		Statics::Assert(false, temp_0097->append(topOfStack_0010->get(0))->toString());
	L00A6: //
		return;
	}

	void CppExecutionContext::generateIFGT(Pointer<IndentedOutputStream> source, Pointer<InstructionIFGT> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> temp_0007;
		Pointer<String> local_0014;
		Pointer<StringBuilder> temp_0051;
		Pointer<StringBuilder> temp_006E;
		Pointer<StringBuilder> temp_0097;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		local_0014 = topOfStack_0010->get(0);
		switch (topOfStack_0010->get(0)->hashCode())
		{
		case (int)0x000197EF:
			goto L002C;
		default:
			goto L008F;
		}
	L002C: //
		if (local_0014->equals(createString("int")))
			goto L003A;
		goto L008F;
	L003A: //
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L0087;
		temp_0051 = new StringBuilder(createString("if (("));
		source->iprintln(temp_0051->append(topOfStack_0010->get(1))->append(createString(") > 0)"))->toString());
		temp_006E = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_006E->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L00A6;
	L0087: //
		this->notSupported(instruction.getValue());
		goto L00A6;
	L008F: //
		temp_0097 = new StringBuilder(createString("IFGT: Unhandled operand type "));
		Statics::__ClassInit();
		Statics::Assert(false, temp_0097->append(topOfStack_0010->get(0))->toString());
	L00A6: //
		return;
	}

	void CppExecutionContext::generateIFLE(Pointer<IndentedOutputStream> source, Pointer<InstructionIFLE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> condition_00A2;
		Pointer<String> temp_0007;
		Pointer<String> local_0014;
		Pointer<StringBuilder> temp_0051;
		Pointer<StringBuilder> temp_006E;
		Pointer<StringBuilder> temp_008E;
		Pointer<StringBuilder> temp_00B4;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		local_0014 = topOfStack_0010->get(0);
		switch (topOfStack_0010->get(0)->hashCode())
		{
		case (int)0x000197EF:
			goto L002C;
		default:
			goto L00AC;
		}
	L002C: //
		if (local_0014->equals(createString("int")))
			goto L003A;
		goto L00AC;
	L003A: //
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L0087;
		temp_0051 = new StringBuilder(createString("if (("));
		source->iprintln(temp_0051->append(topOfStack_0010->get(1))->append(createString(") <= 0)"))->toString());
		temp_006E = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_006E->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L00C3;
	L0087: //
		temp_008E = new StringBuilder(createString("(("));
		condition_00A2 = temp_008E->append(topOfStack_0010->get(1))->append(createString(") > 0)"))->toString();
		this->generateTernary(instruction.getValue(), condition_00A2);
		goto L00C3;
	L00AC: //
		temp_00B4 = new StringBuilder(createString("IFLE: Unhandled operand type "));
		Statics::__ClassInit();
		Statics::Assert(false, temp_00B4->append(topOfStack_0010->get(0))->toString());
	L00C3: //
		return;
	}

	void CppExecutionContext::generateIFLT(Pointer<IndentedOutputStream> source, Pointer<InstructionIFLT> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> condition_00A2;
		Pointer<String> temp_0007;
		Pointer<String> local_0014;
		Pointer<StringBuilder> temp_0051;
		Pointer<StringBuilder> temp_006E;
		Pointer<StringBuilder> temp_008E;
		Pointer<StringBuilder> temp_00B4;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		local_0014 = topOfStack_0010->get(0);
		switch (topOfStack_0010->get(0)->hashCode())
		{
		case (int)0x000197EF:
			goto L002C;
		default:
			goto L00AC;
		}
	L002C: //
		if (local_0014->equals(createString("int")))
			goto L003A;
		goto L00AC;
	L003A: //
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L0087;
		temp_0051 = new StringBuilder(createString("if (("));
		source->iprintln(temp_0051->append(topOfStack_0010->get(1))->append(createString(") < 0)"))->toString());
		temp_006E = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_006E->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L00C3;
	L0087: //
		temp_008E = new StringBuilder(createString("(("));
		condition_00A2 = temp_008E->append(topOfStack_0010->get(1))->append(createString(") >= 0)"))->toString();
		this->generateTernary(instruction.getValue(), condition_00A2);
		goto L00C3;
	L00AC: //
		temp_00B4 = new StringBuilder(createString("IFLT: Unhandled operand type "));
		Statics::__ClassInit();
		Statics::Assert(false, temp_00B4->append(topOfStack_0010->get(0))->toString());
	L00C3: //
		return;
	}

	void CppExecutionContext::generateIFNE(Pointer<IndentedOutputStream> source, Pointer<InstructionIFNE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> condition_00B7;
		Pointer<String> condition_0128;
		Pointer<String> temp_0007;
		Pointer<String> local_0014;
		Pointer<StringBuilder> temp_0066;
		Pointer<StringBuilder> temp_0083;
		Pointer<StringBuilder> temp_00A3;
		Pointer<StringBuilder> temp_00D8;
		Pointer<StringBuilder> temp_00F5;
		Pointer<StringBuilder> temp_0115;
		Pointer<StringBuilder> temp_013A;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		local_0014 = topOfStack_0010->get(0);
		switch (topOfStack_0010->get(0)->hashCode())
		{
		case (int)0x000197EF:
			goto L0034;
		case (int)0x002E3AEA:
			goto L0042;
		default:
			goto L0132;
		}
	L0034: //
		if (local_0014->equals(createString("int")))
			goto L004F;
		goto L0132;
	L0042: //
		if (local_0014->equals(createString("bool")))
			goto L00C1;
		goto L0132;
	L004F: //
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L009C;
		temp_0066 = new StringBuilder(createString("if (("));
		source->iprintln(temp_0066->append(topOfStack_0010->get(1))->append(createString(") != 0)"))->toString());
		temp_0083 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_0083->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L0149;
	L009C: //
		temp_00A3 = new StringBuilder(createString("(("));
		condition_00B7 = temp_00A3->append(topOfStack_0010->get(1))->append(createString(") == 0)"))->toString();
		this->generateTernary(instruction.getValue(), condition_00B7);
		goto L0149;
	L00C1: //
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L010E;
		temp_00D8 = new StringBuilder(createString("if ("));
		source->iprintln(temp_00D8->append(topOfStack_0010->get(1))->append(createString(")"))->toString());
		temp_00F5 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_00F5->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L0149;
	L010E: //
		temp_0115 = new StringBuilder(createString("(!("));
		condition_0128 = temp_0115->append(topOfStack_0010->get(1))->append(createString("))"))->toString();
		this->generateTernary(instruction.getValue(), condition_0128);
		goto L0149;
	L0132: //
		temp_013A = new StringBuilder(createString("IFNE: Unhandled operand type "));
		Statics::__ClassInit();
		Statics::Assert(false, temp_013A->append(topOfStack_0010->get(0))->toString());
	L0149: //
		return;
	}

	void CppExecutionContext::generateIFNONNULL(Pointer<IndentedOutputStream> source, Pointer<InstructionIFNONNULL> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> condition_0078;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_0027;
		Pointer<StringBuilder> temp_0044;
		Pointer<StringBuilder> temp_0064;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L005D;
		temp_0027 = new StringBuilder(createString("if (("));
		source->iprintln(temp_0027->append(topOfStack_0010->get(1))->append(createString(").getValue() != nullptr)"))->toString());
		temp_0044 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_0044->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L007F;
	L005D: //
		temp_0064 = new StringBuilder(createString("(("));
		condition_0078 = temp_0064->append(topOfStack_0010->get(1))->append(createString(").getValue() == nullptr)"))->toString();
		this->generateTernary(instruction.getValue(), condition_0078);
	L007F: //
		return;
	}

	void CppExecutionContext::generateIFNULL(Pointer<IndentedOutputStream> source, Pointer<InstructionIFNULL> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> condition_0078;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_0027;
		Pointer<StringBuilder> temp_0044;
		Pointer<StringBuilder> temp_0064;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		if (!(this->cppMethod->containsStatementAt(instruction->getTargetAddress(0))))
			goto L005D;
		temp_0027 = new StringBuilder(createString("if (("));
		source->iprintln(temp_0027->append(topOfStack_0010->get(1))->append(createString(").getValue() == nullptr)"))->toString());
		temp_0044 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_0044->append(instruction->getTargetLabel())->append(createString(";"))->toString());
		goto L007F;
	L005D: //
		temp_0064 = new StringBuilder(createString("(("));
		condition_0078 = temp_0064->append(topOfStack_0010->get(1))->append(createString(").getValue() != nullptr)"))->toString();
		this->generateTernary(instruction.getValue(), condition_0078);
	L007F: //
		return;
	}

	void CppExecutionContext::generateIINC(Pointer<IndentedOutputStream> source, Pointer<InstructionIINC> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<LocalVariable> local_000D;
		Pointer<StringBuilder> temp_001D;
		Pointer<StringBuilder> temp_0049;
		local_000D = this->locals->get(instruction->getIndex(), instruction.getValue());
		temp_001D = new StringBuilder(createString("IINC: No local "));
		Statics::__ClassInit();
		Statics::Assert(((((local_000D).getValue() != nullptr) ? (1) : (0))) != 0, temp_001D->append(instruction->getIndex())->toString());
		Statics::__ClassInit();
		Statics::Assert(local_000D->getType()->equals(createString("int")), createString("IINC: Local is not int"));
		String::__ClassInit();
		temp_0049 = new StringBuilder(String::valueOf(local_000D->getName().getValue()));
		source->iprintln(temp_0049->append(createString(" += "))->append(instruction->getValue())->append(createString(";"))->toString());
		return;
	}

	void CppExecutionContext::generateILOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionILOAD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		int index_0005 = 0;
		Pointer<LocalVariable> local_0032;
		Pointer<StringBuilder> temp_0043;
		Pointer<StringBuilder> temp_0066;
		index_0005 = instruction->getIndex();
		Statics::__ClassInit();
		Statics::Assert(((((index_0005) >= 0) ? (1) : (0))) != 0, createString("ILOAD: index out of range"));
		Statics::__ClassInit();
		Statics::Assert(((((index_0005) < (this->maxLocals)) ? (1) : (0))) != 0, createString("ILOAD: index out of range"));
		local_0032 = this->locals->get(index_0005, instruction.getValue());
		temp_0043 = new StringBuilder(createString("Local at "));
		Statics::__ClassInit();
		Statics::Assert(((((local_0032).getValue() != nullptr) ? (1) : (0))) != 0, temp_0043->append(index_0005)->append(createString(" is not available"))->toString());
		String::__ClassInit();
		temp_0066 = new StringBuilder(String::valueOf(local_0032->getType().getValue()));
		this->stack->push(temp_0066->append(createString("\t"))->append(local_0032->getName())->toString().getValue());
		return;
	}

	void CppExecutionContext::generateIMUL(Pointer<IndentedOutputStream> source, Pointer<InstructionIMUL> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("int"), createString("*"));
		return;
	}

	void CppExecutionContext::generateINEG(Pointer<IndentedOutputStream> source, Pointer<InstructionINEG> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateINSTANCEOF(Pointer<IndentedOutputStream> source, Pointer<InstructionINSTANCEOF> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> className_0016;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_0033;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		className_0016 = instruction->getClassName();
		Statics::__ClassInit();
		className_0016 = Statics::javaToCppClass(className_0016);
		className_0016 = this->cppClass->simplifyType(className_0016);
		temp_0033 = new StringBuilder(createString("bool\t"));
		this->stack->push(temp_0033->append(topOfStack_0010->get(1))->append(createString("->instanceOf("))->append(className_0016)->append(createString("::__thisClassStatic)"))->toString().getValue());
		return;
	}

	void CppExecutionContext::generateINVOKEDYNAMIC(Pointer<IndentedOutputStream> source, Pointer<InstructionINVOKEDYNAMIC> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateINVOKEINTERFACE(Pointer<IndentedOutputStream> source, Pointer<InstructionINVOKEINTERFACE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> methodCppClass_0008;
		Pointer<String> methodName_0017;
		Pointer<String> methodDescriptor_001D;
		Pointer<JavaArray<String>> parameterTypes_002C;
		int parameterCount_0031 = 0;
		Pointer<JavaArray<String>> parameterValues_0051;
		Pointer<JavaArray<String>> object_0062;
		Pointer<String> returnType_0093;
		Pointer<String> newEntry_00CB;
		Pointer<JavaTypeConverter> temp_0024;
		Pointer<String> temp_0058;
		Pointer<StringBuilder> temp_0078;
		Pointer<StringBuilder> temp_00A7;
		Pointer<StringBuilder> temp_00D4;
		Pointer<StringBuilder> temp_00ED;
		Pointer<StringBuilder> temp_0114;
		Statics::__ClassInit();
		methodCppClass_0008 = Statics::javaToCppClass(instruction->getMethodClassName());
		methodCppClass_0008 = this->cppClass->simplifyType(methodCppClass_0008);
		methodName_0017 = instruction->getMethodName();
		methodDescriptor_001D = instruction->getmethodDescriptor();
		temp_0024 = new JavaTypeConverter(methodDescriptor_001D, false);
		parameterTypes_002C = (JavaArray<String>*)(temp_0024->parseParameterTypes().getValue());
		parameterCount_0031 = parameterTypes_002C->length;
		Statics::__ClassInit();
		Statics::Assert((((((parameterCount_0031) + (1)) == (instruction->getCount())) ? (1) : (0))) != 0, createString("INVOKEINTERFACE: Parameter count mismatch"));
		parameterValues_0051 = (JavaArray<String>*)(this->generateParameters(parameterTypes_002C, parameterCount_0031).getValue());
		temp_0058 = (String*)((this->stack->pop()).getValue());
		temp_0058->checkCast(String::__thisClassStatic);
		object_0062 = (JavaArray<String>*)(temp_0058->split(createString("[\t]")).getValue());
		if (!(object_0062->get(1)->startsWith(createString("new "))))
			goto L008C;
		temp_0078 = new StringBuilder(createString("("));
		object_0062->assign(1, temp_0078->append(object_0062->get(1))->append(createString(")"))->toString());
	L008C: //
		Statics::__ClassInit();
		returnType_0093 = Statics::parseJavaReturnType(methodDescriptor_001D);
		returnType_0093 = this->cppClass->simplifyType(returnType_0093);
		String::__ClassInit();
		temp_00A7 = new StringBuilder(String::valueOf(returnType_0093.getValue()));
		newEntry_00CB = temp_00A7->append(createString("\t"))->append(object_0062->get(1))->append(createString("->"))->append(methodName_0017)->append(createString("("))->toString();
		String::__ClassInit();
		temp_00D4 = new StringBuilder(String::valueOf(newEntry_00CB.getValue()));
		Statics::__ClassInit();
		newEntry_00CB = temp_00D4->append(Statics::commaSeparatedList(parameterValues_0051))->toString();
		String::__ClassInit();
		temp_00ED = new StringBuilder(String::valueOf(newEntry_00CB.getValue()));
		newEntry_00CB = temp_00ED->append(createString(")"))->toString();
		if (!(returnType_0093->equals(createString("void"))))
			goto L0126;
		String::__ClassInit();
		temp_0114 = new StringBuilder(String::valueOf(newEntry_00CB->substring(5).getValue()));
		source->iprintln(temp_0114->append(createString(";"))->toString());
		goto L0130;
	L0126: //
		this->stack->push(newEntry_00CB.getValue());
	L0130: //
		return;
	}

	void CppExecutionContext::generateINVOKESPECIAL(Pointer<IndentedOutputStream> source, Pointer<InstructionINVOKESPECIAL> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> methodDescriptor_0005;
		Pointer<JavaArray<String>> parameterTypes_0020;
		int parameterCount_0025 = 0;
		Pointer<JavaArray<String>> parameterValues_002F;
		Pointer<JavaArray<String>> topOfStack_0040;
		Pointer<String> methodClassName_0049;
		Pointer<String> methodName_004F;
		Pointer<String> simpleBaseClassName_00AF;
		Pointer<String> ctor_00C5;
		bool isGoodTop_0122 = false;
		Pointer<JavaArray<String>> dupInStack_0157;
		Pointer<String> tempName_0190;
		Pointer<JavaTypeConverter> temp_0018;
		Pointer<String> temp_0036;
		Pointer<StringBuilder> temp_00B8;
		Pointer<StringBuilder> temp_00CE;
		Pointer<StringBuilder> temp_00E7;
		Pointer<String> temp_014D;
		Pointer<StringBuilder> temp_017D;
		Pointer<StringBuilder> temp_0199;
		Pointer<StringBuilder> temp_01B3;
		Pointer<StringBuilder> temp_01DC;
		Pointer<StringBuilder> temp_0210;
		Pointer<StringBuilder> temp_0233;
		methodDescriptor_0005 = instruction->getMethodDescriptor();
		Statics::__ClassInit();
		Statics::Assert(methodDescriptor_0005->endsWith(createString(")V")), createString("Constructor must be void"));
		temp_0018 = new JavaTypeConverter(methodDescriptor_0005, false);
		parameterTypes_0020 = (JavaArray<String>*)(temp_0018->parseParameterTypes().getValue());
		parameterCount_0025 = parameterTypes_0020->length;
		parameterValues_002F = (JavaArray<String>*)(this->generateParameters(parameterTypes_0020, parameterCount_0025).getValue());
		temp_0036 = (String*)((this->stack->pop()).getValue());
		temp_0036->checkCast(String::__thisClassStatic);
		topOfStack_0040 = (JavaArray<String>*)(temp_0036->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		methodClassName_0049 = Statics::javaToCppClass(instruction->getMethodClassName());
		methodName_004F = instruction->getMethodName();
		Statics::__ClassInit();
		Statics::Assert(methodName_004F->equals(createString("<init>")), createString("INVOKESPECIAL: <init> expected"));
		if (!(topOfStack_0040->get(0)->equals(this->cppClass->simplifyType(this->classType).getValue())))
			goto L00FC;
		if (!(topOfStack_0040->get(1)->equals(createString("this"))))
			goto L00FC;
		if (methodClassName_0049->equals(this->cppClass->parentClassName.getValue()))
			goto L00A4;
		if (!(this->cppClass->simplifyType(methodClassName_0049)->equals(this->cppClass->className.getValue())))
			goto L00FC;
	L00A4: //
		simpleBaseClassName_00AF = this->cppClass->simplifyType(methodClassName_0049);
		String::__ClassInit();
		temp_00B8 = new StringBuilder(String::valueOf(simpleBaseClassName_00AF.getValue()));
		ctor_00C5 = temp_00B8->append(createString("("))->toString();
		String::__ClassInit();
		temp_00CE = new StringBuilder(String::valueOf(ctor_00C5.getValue()));
		Statics::__ClassInit();
		ctor_00C5 = temp_00CE->append(Statics::commaSeparatedList(parameterValues_002F))->toString();
		String::__ClassInit();
		temp_00E7 = new StringBuilder(String::valueOf(ctor_00C5.getValue()));
		ctor_00C5 = temp_00E7->append(createString(") //"))->toString();
		source->iprintln(ctor_00C5);
		return;
	L00FC: //
		methodClassName_0049 = this->cppClass->simplifyType(methodClassName_0049);
		Statics::__ClassInit();
		Statics::Assert(topOfStack_0040->get(0)->equals(methodClassName_0049.getValue()), createString("Bad stack top"));
		isGoodTop_0122 = topOfStack_0040->get(1)->equals(createString("new"));
		isGoodTop_0122 = (isGoodTop_0122) | (topOfStack_0040->get(1)->equals(createString("this")));
		Statics::__ClassInit();
		Statics::Assert(isGoodTop_0122, createString("Bad stack top"));
		if (!(topOfStack_0040->get(1)->equals(createString("new"))))
			goto L0227;
		temp_014D = (String*)((this->stack->pop()).getValue());
		temp_014D->checkCast(String::__thisClassStatic);
		dupInStack_0157 = (JavaArray<String>*)(temp_014D->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(dupInStack_0157->get(0)->equals(methodClassName_0049.getValue()), createString("Bad stack DUP"));
		Statics::__ClassInit();
		Statics::Assert(dupInStack_0157->get(1)->equals(createString("new")), createString("Bad stack DUP"));
		temp_017D = new StringBuilder(createString("temp_"));
		Statics::__ClassInit();
		tempName_0190 = temp_017D->append(Statics::hexString(instruction->address, 4))->toString();
		String::__ClassInit();
		temp_0199 = new StringBuilder(String::valueOf(methodClassName_0049.getValue()));
		methodClassName_0049 = temp_0199->append(this->addTemplateParameters(methodClassName_0049))->toString();
		temp_01B3 = new StringBuilder(createString("Pointer<"));
		source->liprintln(2, temp_01B3->append(methodClassName_0049)->append(createString("> "))->append(tempName_0190)->append(createString(";"))->toString());
		String::__ClassInit();
		temp_01DC = new StringBuilder(String::valueOf(tempName_0190.getValue()));
		Statics::__ClassInit();
		source->iprintln(temp_01DC->append(createString(" = new "))->append(methodClassName_0049)->append(createString("("))->append(Statics::commaSeparatedList(parameterValues_002F))->append(createString(");"))->toString());
		String::__ClassInit();
		temp_0210 = new StringBuilder(String::valueOf(methodClassName_0049.getValue()));
		this->stack->push(temp_0210->append(createString("\t"))->append(tempName_0190)->toString().getValue());
		goto L0252;
	L0227: //
		String::__ClassInit();
		temp_0233 = new StringBuilder(String::valueOf(topOfStack_0040->get(0).getValue()));
		String::__ClassInit();
		source->iprintln(temp_0233->append(createString("("))->append(String::join(createString(", "), parameterValues_002F.getValue()))->append(createString(")"))->toString());
	L0252: //
		return;
	}

	void CppExecutionContext::generateINVOKESTATIC(Pointer<IndentedOutputStream> source, Pointer<InstructionINVOKESTATIC> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> methodCppClass_0008;
		Pointer<String> methodName_0036;
		Pointer<String> methodDescriptor_003C;
		Pointer<JavaArray<String>> parameterTypes_004B;
		int parameterCount_0050 = 0;
		Pointer<JavaArray<String>> parameterValues_005A;
		Pointer<String> returnType_0061;
		Pointer<String> newEntry_0095;
		Pointer<StringBuilder> temp_0021;
		Pointer<JavaTypeConverter> temp_0043;
		Pointer<StringBuilder> temp_0075;
		Pointer<StringBuilder> temp_009E;
		Pointer<StringBuilder> temp_00B7;
		Pointer<StringBuilder> temp_00DE;
		Statics::__ClassInit();
		methodCppClass_0008 = Statics::javaToCppClass(instruction->getMethodClassName());
		methodCppClass_0008 = this->cppClass->simplifyType(methodCppClass_0008);
		if (this->isStaticConstructor)
			goto L0030;
		String::__ClassInit();
		temp_0021 = new StringBuilder(String::valueOf(methodCppClass_0008.getValue()));
		source->iprintln(temp_0021->append(createString("::__ClassInit();"))->toString());
	L0030: //
		methodName_0036 = instruction->getMethodName();
		methodDescriptor_003C = instruction->getmethodDescriptor();
		temp_0043 = new JavaTypeConverter(methodDescriptor_003C, false);
		parameterTypes_004B = (JavaArray<String>*)(temp_0043->parseParameterTypes().getValue());
		parameterCount_0050 = parameterTypes_004B->length;
		parameterValues_005A = (JavaArray<String>*)(this->generateParameters(parameterTypes_004B, parameterCount_0050).getValue());
		Statics::__ClassInit();
		returnType_0061 = Statics::parseJavaReturnType(methodDescriptor_003C);
		returnType_0061 = this->cppClass->simplifyType(returnType_0061);
		String::__ClassInit();
		temp_0075 = new StringBuilder(String::valueOf(returnType_0061.getValue()));
		newEntry_0095 = temp_0075->append(createString("\t"))->append(methodCppClass_0008)->append(createString("::"))->append(methodName_0036)->append(createString("("))->toString();
		String::__ClassInit();
		temp_009E = new StringBuilder(String::valueOf(newEntry_0095.getValue()));
		Statics::__ClassInit();
		newEntry_0095 = temp_009E->append(Statics::commaSeparatedList(parameterValues_005A))->toString();
		String::__ClassInit();
		temp_00B7 = new StringBuilder(String::valueOf(newEntry_0095.getValue()));
		newEntry_0095 = temp_00B7->append(createString(")"))->toString();
		if (!(returnType_0061->equals(createString("void"))))
			goto L00F0;
		String::__ClassInit();
		temp_00DE = new StringBuilder(String::valueOf(newEntry_0095->substring(5).getValue()));
		source->iprintln(temp_00DE->append(createString(";"))->toString());
		goto L00FA;
	L00F0: //
		this->stack->push(newEntry_0095.getValue());
	L00FA: //
		return;
	}

	void CppExecutionContext::generateINVOKEVIRTUAL(Pointer<IndentedOutputStream> source, Pointer<InstructionINVOKEVIRTUAL> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> methodName_0005;
		Pointer<String> methodDescriptor_000B;
		Pointer<JavaArray<String>> parameterTypes_001A;
		int parameterCount_001F = 0;
		Pointer<JavaArray<String>> parameterValues_0029;
		Pointer<JavaArray<String>> object_003A;
		Pointer<ClassFile> javaClassFile_0073;
		Pointer<ClassMethod> javaClassMethod_0082;
		Pointer<String> fullDescriptor_0089;
		Pointer<String> returnType_0094;
		Pointer<String> newEntry_00E5;
		Pointer<JavaTypeConverter> temp_0012;
		Pointer<String> temp_0030;
		Pointer<StringBuilder> temp_0050;
		Pointer<ClassFile> temp_006E;
		Pointer<StringBuilder> temp_00A8;
		Pointer<StringBuilder> temp_00C2;
		Pointer<StringBuilder> temp_00EE;
		Pointer<StringBuilder> temp_0107;
		Pointer<StringBuilder> temp_012E;
		methodName_0005 = instruction->getMethodName();
		methodDescriptor_000B = instruction->getmethodDescriptor();
		temp_0012 = new JavaTypeConverter(methodDescriptor_000B, false);
		parameterTypes_001A = (JavaArray<String>*)(temp_0012->parseParameterTypes().getValue());
		parameterCount_001F = parameterTypes_001A->length;
		parameterValues_0029 = (JavaArray<String>*)(this->generateParameters(parameterTypes_001A, parameterCount_001F).getValue());
		temp_0030 = (String*)((this->stack->pop()).getValue());
		temp_0030->checkCast(String::__thisClassStatic);
		object_003A = (JavaArray<String>*)(temp_0030->split(createString("[\t]")).getValue());
		if (!(object_003A->get(1)->startsWith(createString("new "))))
			goto L0064;
		temp_0050 = new StringBuilder(createString("("));
		object_003A->assign(1, temp_0050->append(object_003A->get(1))->append(createString(")"))->toString());
	L0064: //
		Recomp::__ClassInit();
		temp_006E = (ClassFile*)((Recomp::processedClasses->get(instruction->getMethodClassName().getValue())).getValue());
		temp_006E->checkCast(ClassFile::__thisClassStatic);
		javaClassFile_0073 = temp_006E;
		if ((javaClassFile_0073).getValue() == nullptr)
			goto L008D;
		javaClassMethod_0082 = javaClassFile_0073->getMethod(methodName_0005, methodDescriptor_000B);
		fullDescriptor_0089 = javaClassMethod_0082->getType();
		methodDescriptor_000B = fullDescriptor_0089;
	L008D: //
		Statics::__ClassInit();
		returnType_0094 = Statics::parseJavaReturnType(methodDescriptor_000B);
		returnType_0094 = this->cppClass->simplifyType(returnType_0094);
		String::__ClassInit();
		temp_00A8 = new StringBuilder(String::valueOf(returnType_0094.getValue()));
		returnType_0094 = temp_00A8->append(this->addTemplateParameters(returnType_0094))->toString();
		String::__ClassInit();
		temp_00C2 = new StringBuilder(String::valueOf(returnType_0094.getValue()));
		newEntry_00E5 = temp_00C2->append(createString("\t"))->append(object_003A->get(1))->append(createString("->"))->append(methodName_0005)->append(createString("("))->toString();
		String::__ClassInit();
		temp_00EE = new StringBuilder(String::valueOf(newEntry_00E5.getValue()));
		Statics::__ClassInit();
		newEntry_00E5 = temp_00EE->append(Statics::commaSeparatedList(parameterValues_0029))->toString();
		String::__ClassInit();
		temp_0107 = new StringBuilder(String::valueOf(newEntry_00E5.getValue()));
		newEntry_00E5 = temp_0107->append(createString(")"))->toString();
		if (!(returnType_0094->equals(createString("void"))))
			goto L0140;
		String::__ClassInit();
		temp_012E = new StringBuilder(String::valueOf(newEntry_00E5->substring(5).getValue()));
		source->iprintln(temp_012E->append(createString(";"))->toString());
		goto L014A;
	L0140: //
		this->stack->push(newEntry_00E5.getValue());
	L014A: //
		return;
	}

	void CppExecutionContext::generateIOR(Pointer<IndentedOutputStream> source, Pointer<InstructionIOR> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("int|bool"), createString("|"));
		return;
	}

	void CppExecutionContext::generateIREM(Pointer<IndentedOutputStream> source, Pointer<InstructionIREM> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateIRETURN(Pointer<IndentedOutputStream> source, Pointer<InstructionIRETURN> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> value_0010;
		bool isType_001B = false;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_0038;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		value_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		isType_001B = value_0010->get(0)->equals(createString("int"));
		isType_001B = (isType_001B) | (value_0010->get(0)->equals(createString("bool")));
		Statics::__ClassInit();
		Statics::Assert(isType_001B, createString("IRETURN: Integer or boolean expected"));
		temp_0038 = new StringBuilder(createString("return "));
		source->iprintln(temp_0038->append(value_0010->get(1))->append(createString(";"))->toString());
		return;
	}

	void CppExecutionContext::generateISHL(Pointer<IndentedOutputStream> source, Pointer<InstructionISHL> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> shift_0010;
		Pointer<JavaArray<String>> value_0021;
		Pointer<String> newEntry_0068;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_0047;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		shift_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		value_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(value_0021->get(0)->equals(createString("int")), createString("ISHL: Integer value and shift expected"));
		Statics::__ClassInit();
		Statics::Assert(shift_0010->get(0)->equals(createString("int")), createString("ISHL: Integer value and shift expected"));
		temp_0047 = new StringBuilder(createString("int\t_shlx_u32("));
		newEntry_0068 = temp_0047->append(value_0021->get(1))->append(createString(", ("))->append(shift_0010->get(1))->append(createString(") & 0x1F)"))->toString();
		this->stack->push(newEntry_0068.getValue());
		return;
	}

	void CppExecutionContext::generateISHR(Pointer<IndentedOutputStream> source, Pointer<InstructionISHR> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> shift_0010;
		Pointer<JavaArray<String>> value_0021;
		Pointer<String> newEntry_0068;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_0047;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		shift_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		value_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(value_0021->get(0)->equals(createString("int")), createString("ISHR: Integer value and shift expected"));
		Statics::__ClassInit();
		Statics::Assert(shift_0010->get(0)->equals(createString("int")), createString("ISHR: Integer value and shift expected"));
		temp_0047 = new StringBuilder(createString("int\t_sarx_i32("));
		newEntry_0068 = temp_0047->append(value_0021->get(1))->append(createString(", ("))->append(shift_0010->get(1))->append(createString(") & 0x1F)"))->toString();
		this->stack->push(newEntry_0068.getValue());
		return;
	}

	void CppExecutionContext::generateISTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionISTORE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		int index_0005 = 0;
		Pointer<LocalVariable> local_0032;
		Pointer<JavaArray<String>> topOfStack_0043;
		Pointer<String> type_0048;
		bool isType_0085 = false;
		Pointer<String> initializer_00B1;
		Pointer<String> temp_0039;
		Pointer<StringBuilder> temp_006A;
		Pointer<StringBuilder> temp_00FB;
		Pointer<StringBuilder> temp_012A;
		index_0005 = instruction->getIndex();
		Statics::__ClassInit();
		Statics::Assert(((((index_0005) >= 0) ? (1) : (0))) != 0, createString("Local index out of range"));
		Statics::__ClassInit();
		Statics::Assert(((((index_0005) < (this->maxLocals)) ? (1) : (0))) != 0, createString("Local index out of range"));
		local_0032 = this->locals->get(index_0005, instruction.getValue());
		temp_0039 = (String*)((this->stack->pop()).getValue());
		temp_0039->checkCast(String::__thisClassStatic);
		topOfStack_0043 = (JavaArray<String>*)(temp_0039->split(createString("[\t]")).getValue());
		type_0048 = createString("");
		if ((local_0032).getValue() != nullptr)
			goto L0078;
		local_0032 = this->locals->set(index_0005, topOfStack_0043->get(0), instruction->address);
		String::__ClassInit();
		temp_006A = new StringBuilder(String::valueOf(topOfStack_0043->get(0).getValue()));
		type_0048 = temp_006A->append(createString(" "))->toString();
	L0078: //
		isType_0085 = local_0032->getType()->equals(createString("int"));
		isType_0085 = (isType_0085) | (local_0032->getType()->equals(createString("bool")));
		isType_0085 = (isType_0085) | (local_0032->getType()->equals(createString("char")));
		Statics::__ClassInit();
		Statics::Assert(isType_0085, createString("ISTORE: Integer or boolean expected"));
		initializer_00B1 = createString("0");
		if (!(topOfStack_0043->get(0)->equals(createString("int"))))
			goto L00D6;
		if (!(local_0032->getType()->equals(createString("bool"))))
			goto L00D6;
		topOfStack_0043->assign(0, createString("bool"));
		initializer_00B1 = createString("false");
	L00D6: //
		Statics::__ClassInit();
		Statics::Assert(local_0032->getType()->equals(topOfStack_0043->get(0).getValue()), createString("ISTORE: Type mismatch"));
		if ((type_0048->length()) <= 0)
			goto L011D;
		String::__ClassInit();
		temp_00FB = new StringBuilder(String::valueOf(type_0048.getValue()));
		source->liprintln(2, temp_00FB->append(local_0032->getName())->append(createString(" = "))->append(initializer_00B1)->append(createString(";"))->toString());
	L011D: //
		String::__ClassInit();
		temp_012A = new StringBuilder(String::valueOf(local_0032->getName().getValue()));
		source->iprintln(temp_012A->append(createString(" = "))->append(topOfStack_0043->get(1))->append(createString(";"))->toString());
		return;
	}

	void CppExecutionContext::generateISUB(Pointer<IndentedOutputStream> source, Pointer<InstructionISUB> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("int"), createString("-"));
		return;
	}

	void CppExecutionContext::generateIUSHR(Pointer<IndentedOutputStream> source, Pointer<InstructionIUSHR> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> shift_0010;
		Pointer<JavaArray<String>> value_0021;
		Pointer<String> newEntry_0068;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_0047;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		shift_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		value_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(value_0021->get(0)->equals(createString("int")), createString("IUSHR: Integer value and shift expected"));
		Statics::__ClassInit();
		Statics::Assert(shift_0010->get(0)->equals(createString("int")), createString("IUSHR: Integer value and shift expected"));
		temp_0047 = new StringBuilder(createString("int\t_shrx_u32("));
		newEntry_0068 = temp_0047->append(value_0021->get(1))->append(createString(", ("))->append(shift_0010->get(1))->append(createString(") & 0x1F)"))->toString();
		this->stack->push(newEntry_0068.getValue());
		return;
	}

	void CppExecutionContext::generateIXOR(Pointer<IndentedOutputStream> source, Pointer<InstructionIXOR> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("int"), createString("^"));
		return;
	}

	void CppExecutionContext::generateJSR(Pointer<IndentedOutputStream> source, Pointer<InstructionJSR> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateJSR_W(Pointer<IndentedOutputStream> source, Pointer<InstructionJSR_W> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateL2D(Pointer<IndentedOutputStream> source, Pointer<InstructionL2D> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("INT64"), createString("double"));
		return;
	}

	void CppExecutionContext::generateL2F(Pointer<IndentedOutputStream> source, Pointer<InstructionL2F> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("INT64"), createString("float"));
		return;
	}

	void CppExecutionContext::generateL2I(Pointer<IndentedOutputStream> source, Pointer<InstructionL2I> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateConversion(instruction.getValue(), createString("INT64"), createString("int"));
		return;
	}

	void CppExecutionContext::generateLADD(Pointer<IndentedOutputStream> source, Pointer<InstructionLADD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("INT64"), createString("+"));
		return;
	}

	void CppExecutionContext::generateLALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionLALOAD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateLAND(Pointer<IndentedOutputStream> source, Pointer<InstructionLAND> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("INT64"), createString("&"));
		return;
	}

	void CppExecutionContext::generateLASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionLASTORE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateLCMP(Pointer<IndentedOutputStream> source, Pointer<InstructionLCMP> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateLCONST(Pointer<IndentedOutputStream> source, Pointer<InstructionLCONST> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> newEntry_0015;
		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("INT64\t"));
		newEntry_0015 = temp_0007->append(instruction->getValue())->toString();
		this->stack->push(newEntry_0015.getValue());
		return;
	}

	void CppExecutionContext::generateLDC(Pointer<IndentedOutputStream> source, Pointer<InstructionLDC> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateLoadConstant(instruction->getConstant());
		return;
	}

	void CppExecutionContext::generateLDC_W(Pointer<IndentedOutputStream> source, Pointer<InstructionLDC_W> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateLoadConstant(instruction->getConstant());
		return;
	}

	void CppExecutionContext::generateLDC2_W(Pointer<IndentedOutputStream> source, Pointer<InstructionLDC2_W> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateLoadConstant(instruction->getConstant());
		return;
	}

	void CppExecutionContext::generateLDIV(Pointer<IndentedOutputStream> source, Pointer<InstructionLDIV> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("INT64"), createString("/"));
		return;
	}

	void CppExecutionContext::generateLLOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionLLOAD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateXLOAD(source, instruction.getValue(), createString("INT64"));
		return;
	}

	void CppExecutionContext::generateLMUL(Pointer<IndentedOutputStream> source, Pointer<InstructionLMUL> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("INT64"), createString("/"));
		return;
	}

	void CppExecutionContext::generateLNEG(Pointer<IndentedOutputStream> source, Pointer<InstructionLNEG> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateLoadConstant(Pointer<Constant> constant)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> newEntry_0004;
		Pointer<ConstantStringInfo> stringValue_001E;
		Pointer<Constant>  instanceOfPatternExpressionValue_0007;
		Pointer<String> type_002A;
		Pointer<ConstantInteger> intValue_0071;
		Pointer<Constant>  instanceOfPatternExpressionValue_0059;
		Pointer<ConstantFloat> floatValue_00A5;
		Pointer<Constant>  instanceOfPatternExpressionValue_008D;
		Pointer<ConstantDouble> doubleValue_00D9;
		Pointer<Constant>  instanceOfPatternExpressionValue_00C1;
		Pointer<ConstantClassInfo> classInfo_010D;
		Pointer<Constant>  instanceOfPatternExpressionValue_00F5;
		Pointer<ConstantStringInfo> temp_0011;
		Pointer<ConstantStringInfo> local_0015;
		Pointer<ConstantStringInfo> temp_0018;
		Pointer<StringBuilder> temp_0033;
		Pointer<ConstantInteger> temp_0063;
		Pointer<ConstantInteger> local_0067;
		Pointer<ConstantInteger> temp_006B;
		Pointer<StringBuilder> temp_0078;
		Pointer<ConstantFloat> temp_0097;
		Pointer<ConstantFloat> local_009B;
		Pointer<ConstantFloat> temp_009F;
		Pointer<StringBuilder> temp_00AC;
		Pointer<ConstantDouble> temp_00CB;
		Pointer<ConstantDouble> local_00CF;
		Pointer<ConstantDouble> temp_00D3;
		Pointer<StringBuilder> temp_00E0;
		Pointer<ConstantClassInfo> temp_00FF;
		Pointer<ConstantClassInfo> local_0103;
		Pointer<ConstantClassInfo> temp_0107;
		Pointer<StringBuilder> temp_0114;
		Pointer<StringBuilder> temp_0131;
		Pointer<RuntimeException> temp_014C;
		newEntry_0004 = createString("");
		 instanceOfPatternExpressionValue_0007 = constant;
		if (!( instanceOfPatternExpressionValue_0007->instanceOf(ConstantStringInfo::__thisClassStatic)))
			goto L0056;
		temp_0011 = (ConstantStringInfo*)(( instanceOfPatternExpressionValue_0007).getValue());
		temp_0011->checkCast(ConstantStringInfo::__thisClassStatic);
		local_0015 = temp_0011;
		temp_0018 = (ConstantStringInfo*)(( instanceOfPatternExpressionValue_0007).getValue());
		temp_0018->checkCast(ConstantStringInfo::__thisClassStatic);
		if ((temp_0011) != (temp_0018))
			goto L0056;
		type_002A = this->cppClass->simplifyType(createString("java::lang::String"));
		String::__ClassInit();
		temp_0033 = new StringBuilder(String::valueOf(type_002A.getValue()));
		Statics::__ClassInit();
		newEntry_0004 = temp_0033->append(createString("\t"))->append(createString("\""))->append(Statics::escapeCharacters(stringValue_001E->getString()))->append(createString("\""))->toString();
		goto L0150;
	L0056: //
		 instanceOfPatternExpressionValue_0059 = constant;
		if (!( instanceOfPatternExpressionValue_0059->instanceOf(ConstantInteger::__thisClassStatic)))
			goto L008A;
		temp_0063 = (ConstantInteger*)(( instanceOfPatternExpressionValue_0059).getValue());
		temp_0063->checkCast(ConstantInteger::__thisClassStatic);
		local_0067 = temp_0063;
		temp_006B = (ConstantInteger*)(( instanceOfPatternExpressionValue_0059).getValue());
		temp_006B->checkCast(ConstantInteger::__thisClassStatic);
		if ((temp_0063) != (temp_006B))
			goto L008A;
		temp_0078 = new StringBuilder(createString("int\t"));
		newEntry_0004 = temp_0078->append(intValue_0071->getValue())->toString();
		goto L0150;
	L008A: //
		 instanceOfPatternExpressionValue_008D = constant;
		if (!( instanceOfPatternExpressionValue_008D->instanceOf(ConstantFloat::__thisClassStatic)))
			goto L00BE;
		temp_0097 = (ConstantFloat*)(( instanceOfPatternExpressionValue_008D).getValue());
		temp_0097->checkCast(ConstantFloat::__thisClassStatic);
		local_009B = temp_0097;
		temp_009F = (ConstantFloat*)(( instanceOfPatternExpressionValue_008D).getValue());
		temp_009F->checkCast(ConstantFloat::__thisClassStatic);
		if ((temp_0097) != (temp_009F))
			goto L00BE;
		temp_00AC = new StringBuilder(createString("float\t"));
		newEntry_0004 = temp_00AC->append(floatValue_00A5->getValue())->toString();
		goto L0150;
	L00BE: //
		 instanceOfPatternExpressionValue_00C1 = constant;
		if (!( instanceOfPatternExpressionValue_00C1->instanceOf(ConstantDouble::__thisClassStatic)))
			goto L00F2;
		temp_00CB = (ConstantDouble*)(( instanceOfPatternExpressionValue_00C1).getValue());
		temp_00CB->checkCast(ConstantDouble::__thisClassStatic);
		local_00CF = temp_00CB;
		temp_00D3 = (ConstantDouble*)(( instanceOfPatternExpressionValue_00C1).getValue());
		temp_00D3->checkCast(ConstantDouble::__thisClassStatic);
		if ((temp_00CB) != (temp_00D3))
			goto L00F2;
		temp_00E0 = new StringBuilder(createString("double\t"));
		newEntry_0004 = temp_00E0->append(doubleValue_00D9->getValue())->toString();
		goto L0150;
	L00F2: //
		 instanceOfPatternExpressionValue_00F5 = constant;
		if (!( instanceOfPatternExpressionValue_00F5->instanceOf(ConstantClassInfo::__thisClassStatic)))
			goto L0126;
		temp_00FF = (ConstantClassInfo*)(( instanceOfPatternExpressionValue_00F5).getValue());
		temp_00FF->checkCast(ConstantClassInfo::__thisClassStatic);
		local_0103 = temp_00FF;
		temp_0107 = (ConstantClassInfo*)(( instanceOfPatternExpressionValue_00F5).getValue());
		temp_0107->checkCast(ConstantClassInfo::__thisClassStatic);
		if ((temp_00FF) != (temp_0107))
			goto L0126;
		temp_0114 = new StringBuilder(createString("class\t"));
		newEntry_0004 = temp_0114->append(classInfo_010D->getValue())->toString();
		goto L0150;
	L0126: //
		temp_0131 = new StringBuilder(createString("LDC: Constant type "));
		temp_014C = new RuntimeException(temp_0131->append(constant->getClass()->getSimpleName()->substring(8))->append(createString(" not implemented"))->toString());
		throw temp_014C;
	L0150: //
		Statics::__ClassInit();
		Statics::Assert(((((newEntry_0004->length()) > 0) ? (1) : (0))) != 0, createString("LDC: Empty constant"));
		this->stack->push(newEntry_0004.getValue());
		return;
	}

	void CppExecutionContext::generateLOOKUPSWITCH(Pointer<IndentedOutputStream> source, Pointer<InstructionLOOKUPSWITCH> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		bool isType_001B = false;
		int i_0058 = 0;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_0039;
		Pointer<StringBuilder> temp_0063;
		Pointer<StringBuilder> temp_0088;
		Pointer<StringBuilder> temp_00BB;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		isType_001B = topOfStack_0010->get(0)->equals(createString("int"));
		isType_001B = (isType_001B) | (topOfStack_0010->get(0)->equals(createString("char")));
		Statics::__ClassInit();
		Statics::Assert(isType_001B, createString("LOOKUPSWITCH: Integer or character expected"));
		temp_0039 = new StringBuilder(createString("switch ("));
		source->iprintln(temp_0039->append(topOfStack_0010->get(1))->append(createString(")"))->toString());
		source->iprintln(createString("{"));
		i_0058 = 0;
		goto L00A3;
	L005B: //
		temp_0063 = new StringBuilder(createString("case (int)0x"));
		Statics::__ClassInit();
		source->iprintln(temp_0063->append(Statics::hexString(instruction->getMatch(i_0058), 8))->append(createString(":"))->toString());
		temp_0088 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_0088->append(instruction->getLabel(i_0058))->append(createString(";"))->toString());
		i_0058 += 1;
	L00A3: //
		if ((i_0058) < (instruction->getCaseCount()))
			goto L005B;
		source->iprintln(createString("default:"));
		temp_00BB = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_00BB->append(instruction->getDefaultLabel())->append(createString(";"))->toString());
		source->iprintln(createString("}"));
		return;
	}

	void CppExecutionContext::generateLOR(Pointer<IndentedOutputStream> source, Pointer<InstructionLOR> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("INT64"), createString("|"));
		return;
	}

	void CppExecutionContext::generateLREM(Pointer<IndentedOutputStream> source, Pointer<InstructionLREM> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("INT64"), createString("%"));
		return;
	}

	void CppExecutionContext::generateLRETURN(Pointer<IndentedOutputStream> source, Pointer<InstructionLRETURN> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateXRETURN(source, instruction.getValue(), createString("INT64"));
		return;
	}

	void CppExecutionContext::generateLSHL(Pointer<IndentedOutputStream> source, Pointer<InstructionLSHL> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> shift_0010;
		Pointer<JavaArray<String>> value_0021;
		Pointer<String> newEntry_0068;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_0047;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		shift_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		value_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(value_0021->get(0)->equals(createString("INT64")), createString("LSHL: Long value and integer shift expected"));
		Statics::__ClassInit();
		Statics::Assert(shift_0010->get(0)->equals(createString("int")), createString("LSHL: Long value and integer shift expected"));
		temp_0047 = new StringBuilder(createString("INT64\t_shlx_u64("));
		newEntry_0068 = temp_0047->append(value_0021->get(1))->append(createString(", ("))->append(shift_0010->get(1))->append(createString(") & 0x3F)"))->toString();
		this->stack->push(newEntry_0068.getValue());
		return;
	}

	void CppExecutionContext::generateLSHR(Pointer<IndentedOutputStream> source, Pointer<InstructionLSHR> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> shift_0010;
		Pointer<JavaArray<String>> value_0021;
		Pointer<String> newEntry_0068;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_0047;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		shift_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		value_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(value_0021->get(0)->equals(createString("INT64")), createString("LSHR: Long value and integer shift expected"));
		Statics::__ClassInit();
		Statics::Assert(shift_0010->get(0)->equals(createString("int")), createString("LSHR: Long value and integer shift expected"));
		temp_0047 = new StringBuilder(createString("INT64\t_sarx_i64("));
		newEntry_0068 = temp_0047->append(value_0021->get(1))->append(createString(", ("))->append(shift_0010->get(1))->append(createString(") & 0x3F)"))->toString();
		this->stack->push(newEntry_0068.getValue());
		return;
	}

	void CppExecutionContext::generateLSTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionLSTORE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateXSTORE(source, instruction.getValue(), createString("INT64"));
		return;
	}

	void CppExecutionContext::generateLSUB(Pointer<IndentedOutputStream> source, Pointer<InstructionLSUB> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("INT64"), createString("-"));
		return;
	}

	void CppExecutionContext::generateLUSHR(Pointer<IndentedOutputStream> source, Pointer<InstructionLUSHR> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> shift_0010;
		Pointer<JavaArray<String>> value_0021;
		Pointer<String> newEntry_0068;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<StringBuilder> temp_0047;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		shift_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		value_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(value_0021->get(0)->equals(createString("INT64")), createString("LUSHR: Long value and integer shift expected"));
		Statics::__ClassInit();
		Statics::Assert(shift_0010->get(0)->equals(createString("int")), createString("LUSHR: Long value and integer shift expected"));
		temp_0047 = new StringBuilder(createString("INT64\t_shrx_u64("));
		newEntry_0068 = temp_0047->append(value_0021->get(1))->append(createString(", ("))->append(shift_0010->get(1))->append(createString(") & 0x3F)"))->toString();
		this->stack->push(newEntry_0068.getValue());
		return;
	}

	void CppExecutionContext::generateLXOR(Pointer<IndentedOutputStream> source, Pointer<InstructionLXOR> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generateBinaryOp(source, instruction.getValue(), createString("INT64"), createString("^"));
		return;
	}

	void CppExecutionContext::generateMONITORENTER(Pointer<IndentedOutputStream> source, Pointer<InstructionMONITORENTER> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateMONITOREXIT(Pointer<IndentedOutputStream> source, Pointer<InstructionMONITOREXIT> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateMULTIANEWARRAY(Pointer<IndentedOutputStream> source, Pointer<InstructionMULTIANEWARRAY> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateNEW(Pointer<IndentedOutputStream> source, Pointer<InstructionNEW> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0008;
		Pointer<String> simpleClassName_0012;
		Pointer<StringBuilder> temp_001F;
		Statics::__ClassInit();
		className_0008 = Statics::javaToCppClass(instruction->getClassName());
		simpleClassName_0012 = this->cppClass->simplifyType(className_0008);
		String::__ClassInit();
		temp_001F = new StringBuilder(String::valueOf(simpleClassName_0012.getValue()));
		this->stack->push(temp_001F->append(createString("\t"))->append(createString("new"))->toString().getValue());
		return;
	}

	void CppExecutionContext::generateNEWARRAY(Pointer<IndentedOutputStream> source, Pointer<InstructionNEWARRAY> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		Pointer<String> length_0024;
		Pointer<String> type_002A;
		Pointer<String> tempName_0044;
		Pointer<String> newEntry_00BF;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_0031;
		Pointer<StringBuilder> temp_004D;
		Pointer<StringBuilder> temp_0076;
		Pointer<StringBuilder> temp_00A2;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		Statics::__ClassInit();
		Statics::Assert(topOfStack_0010->get(0)->equals(createString("int")), createString("NEWARRAY: Integer operand expected"));
		length_0024 = topOfStack_0010->get(1);
		type_002A = instruction->getElementType();
		temp_0031 = new StringBuilder(createString("temp_"));
		Statics::__ClassInit();
		tempName_0044 = temp_0031->append(Statics::hexString(instruction->address, 4))->toString();
		temp_004D = new StringBuilder(createString("Pointer<JavaRawArray<"));
		source->liprintln(2, temp_004D->append(type_002A)->append(createString(">> "))->append(tempName_0044)->append(createString(";"))->toString());
		String::__ClassInit();
		temp_0076 = new StringBuilder(String::valueOf(tempName_0044.getValue()));
		source->iprintln(temp_0076->append(createString(" = new JavaRawArray<"))->append(type_002A)->append(createString(">("))->append(length_0024)->append(createString(");"))->toString());
		temp_00A2 = new StringBuilder(createString("JavaRawArray<"));
		newEntry_00BF = temp_00A2->append(type_002A)->append(createString(">"))->append(createString("\t"))->append(tempName_0044)->toString();
		this->stack->push(newEntry_00BF.getValue());
		return;
	}

	void CppExecutionContext::generateNOP(Pointer<IndentedOutputStream> source, Pointer<InstructionNOP> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	Pointer<JavaArray<String>> CppExecutionContext::generateParameters(Pointer<JavaArray<String>> parameterTypes, int parameterCount)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> parameterValues_0005;
		int i_0008 = 0;
		Pointer<JavaArray<String>> stackEntry_001C;
		int parameterIndex_0024 = 0;
		Pointer<String> simpleType_0031;
		Pointer<String> getValue_0036;
		int value_0181 = 0;
		Pointer<String> ch_01AB;
		Pointer<String> str_01B2;
		Pointer<JavaArray<String>> temp_0001;
		Pointer<String> temp_0012;
		Pointer<StringBuilder> temp_0057;
		Pointer<StringBuilder> temp_00B7;
		Pointer<String> local_00C9;
		Pointer<String> local_0109;
		Pointer<StringBuilder> temp_0161;
		Pointer<StringBuilder> temp_01BC;
		Pointer<StringBuilder> temp_01DB;
		Pointer<StringBuilder> temp_01FD;
		Pointer<StringBuilder> temp_0222;
		temp_0001 = new JavaArray<String>(parameterCount);
		parameterValues_0005 = (JavaArray<String>*)(temp_0001.getValue());
		i_0008 = 0;
		goto L0231;
	L000B: //
		temp_0012 = (String*)((this->stack->pop()).getValue());
		temp_0012->checkCast(String::__thisClassStatic);
		stackEntry_001C = (JavaArray<String>*)(temp_0012->split(createString("[\t]")).getValue());
		parameterIndex_0024 = ((parameterCount) - (1)) - (i_0008);
		simpleType_0031 = this->cppClass->simplifyType(parameterTypes->get(parameterIndex_0024));
		getValue_0036 = createString("");
		if (!(stackEntry_001C->get(0)->equals(createString("nullptr"))))
			goto L006C;
		if (!(stackEntry_001C->get(1)->equals(createString("nullptr"))))
			goto L006C;
		temp_0057 = new StringBuilder(createString("("));
		stackEntry_001C->assign(1, temp_0057->append(simpleType_0031)->append(createString("*) nullptr"))->toString());
		goto L0095;
	L006C: //
		if (simpleType_0031->equals(parameterTypes->get(parameterIndex_0024).getValue()))
			goto L0095;
		if (simpleType_0031->equals(stackEntry_001C->get(0).getValue()))
			goto L0095;
		if (stackEntry_001C->get(1)->startsWith(createString("\"")))
			goto L0095;
		getValue_0036 = createString(".getValue()");
	L0095: //
		if (stackEntry_001C->get(0)->equals(simpleType_0031.getValue()))
			goto L01E7;
		if (!(getValue_0036->equals(createString(""))))
			goto L01E7;
		String::__ClassInit();
		temp_00B7 = new StringBuilder(String::valueOf(stackEntry_001C->get(0).getValue()));
		local_00C9 = temp_00B7->append(createString(":"))->append(simpleType_0031)->toString();
		switch (temp_00B7->append(createString(":"))->append(simpleType_0031)->toString()->hashCode())
		{
		case (int)0x1F9A9395:
			goto L00E8;
		case (int)0x1F9AEC01:
			goto L00F6;
		default:
			goto L01E7;
		}
	L00E8: //
		if (local_00C9->equals(createString("int:bool")))
			goto L0104;
		goto L01E7;
	L00F6: //
		if (local_00C9->equals(createString("int:char")))
			goto L0178;
		goto L01E7;
	L0104: //
		local_0109 = stackEntry_001C->get(1);
		switch (stackEntry_001C->get(1)->hashCode())
		{
		case (int)0x00000030:
			goto L0128;
		case (int)0x00000031:
			goto L0136;
		default:
			goto L0158;
		}
	L0128: //
		if (local_0109->equals(createString("0")))
			goto L0144;
		goto L0158;
	L0136: //
		if (local_0109->equals(createString("1")))
			goto L014E;
		goto L0158;
	L0144: //
		stackEntry_001C->assign(1, createString("false"));
		goto L01E7;
	L014E: //
		stackEntry_001C->assign(1, createString("true"));
		goto L01E7;
	L0158: //
		temp_0161 = new StringBuilder(createString("("));
		stackEntry_001C->assign(1, temp_0161->append(stackEntry_001C->get(1))->append(createString(") != 0"))->toString());
		goto L01E7;
	L0178: //
		Integer::__ClassInit();
		value_0181 = Integer::parseInt(stackEntry_001C->get(1));
		if ((value_0181) < (32))
			goto L018F;
		if ((value_0181) <= (126))
			goto L01A4;
	L018F: //
		if ((value_0181) == (13))
			goto L01A4;
		if ((value_0181) == (10))
			goto L01A4;
		if ((value_0181) != (9))
			goto L01D1;
	L01A4: //
		Character::__ClassInit();
		ch_01AB = Character::toString(value_0181);
		Statics::__ClassInit();
		str_01B2 = Statics::escapeCharacters(ch_01AB);
		temp_01BC = new StringBuilder(createString("\'"));
		stackEntry_001C->assign(1, temp_01BC->append(str_01B2)->append(createString("\'"))->toString());
		goto L01E7;
	L01D1: //
		temp_01DB = new StringBuilder(createString("(char)"));
		stackEntry_001C->assign(1, temp_01DB->append(value_0181)->toString());
	L01E7: //
		if (!(stackEntry_001C->get(1)->startsWith(createString("\""))))
			goto L0214;
		temp_01FD = new StringBuilder(createString("createString("));
		parameterValues_0005->assign(parameterIndex_0024, temp_01FD->append(stackEntry_001C->get(1))->append(createString(")"))->toString());
		goto L022E;
	L0214: //
		String::__ClassInit();
		temp_0222 = new StringBuilder(String::valueOf(stackEntry_001C->get(1).getValue()));
		parameterValues_0005->assign(parameterIndex_0024, temp_0222->append(getValue_0036)->toString());
	L022E: //
		i_0008 += 1;
	L0231: //
		if ((i_0008) < (parameterCount))
			goto L000B;
		return parameterValues_0005;
	}

	void CppExecutionContext::generatePOP(Pointer<IndentedOutputStream> source, Pointer<InstructionPOP> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> value_0010;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_001B;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		value_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		String::__ClassInit();
		temp_001B = new StringBuilder(String::valueOf(value_0010->get(1).getValue()));
		source->iprintln(temp_001B->append(createString(";"))->toString());
		return;
	}

	void CppExecutionContext::generatePOP2(Pointer<IndentedOutputStream> source, Pointer<InstructionPOP2> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generatePUTFIELD(Pointer<IndentedOutputStream> source, Pointer<InstructionPUTFIELD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> value_0010;
		Pointer<JavaArray<String>> object_0021;
		Pointer<String> className_0032;
		Pointer<String> fieldName_0043;
		Pointer<String> fqClassName_0050;
		Pointer<String> fieldType_0062;
		Pointer<String> getValue_0094;
		Pointer<String> cast_0099;
		Pointer<String> temp_0007;
		Pointer<String> temp_0017;
		Pointer<JavaTypeConverter> temp_002A;
		Pointer<String> temp_004B;
		Pointer<ClassFile> temp_0058;
		Pointer<JavaTypeConverter> temp_0069;
		Pointer<StringBuilder> temp_00AA;
		Pointer<StringBuilder> temp_00FA;
		Pointer<StringBuilder> temp_0132;
		Pointer<String> local_0144;
		Pointer<String> local_0173;
		Pointer<StringBuilder> temp_01CA;
		Pointer<StringBuilder> temp_01E9;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		value_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		temp_0017 = (String*)((this->stack->pop()).getValue());
		temp_0017->checkCast(String::__thisClassStatic);
		object_0021 = (JavaArray<String>*)(temp_0017->split(createString("[\t]")).getValue());
		temp_002A = new JavaTypeConverter(instruction->getClassName(), true);
		className_0032 = temp_002A->getCppType();
		className_0032 = this->cppClass->simplifyType(className_0032);
		fieldName_0043 = instruction->getFieldName();
		Recomp::__ClassInit();
		temp_004B = (String*)((Recomp::simpleClassNames->get(className_0032.getValue())).getValue());
		temp_004B->checkCast(String::__thisClassStatic);
		fqClassName_0050 = temp_004B;
		Recomp::__ClassInit();
		temp_0058 = (ClassFile*)((Recomp::processedClasses->get(fqClassName_0050.getValue())).getValue());
		temp_0058->checkCast(ClassFile::__thisClassStatic);
		fieldType_0062 = temp_0058->getFieldType(fieldName_0043);
		temp_0069 = new JavaTypeConverter(fieldType_0062, true);
		fieldType_0062 = temp_0069->getCppType();
		fieldType_0062 = this->cppClass->simplifyType(fieldType_0062);
		getValue_0094 = ((instruction->getFieldType()->startsWith(createString("L"))) ? (((Pointer<String>) new String(".getValue()"))) : (((Pointer<String>) new String(""))));
		cast_0099 = createString("");
		if (fieldType_0062->equals(value_0010->get(0).getValue()))
			goto L00D6;
		temp_00AA = new StringBuilder(createString("("));
		cast_0099 = temp_00AA->append(fieldType_0062)->append(((instruction->getFieldType()->startsWith(createString("L"))) ? (((Pointer<String>) new String("*"))) : (((Pointer<String>) new String("")))))->append(createString(")"))->toString();
	L00D6: //
		if (!(fieldType_0062->equals(createString("String"))))
			goto L0112;
		if (!(value_0010->get(1)->startsWith(createString("\""))))
			goto L0112;
		cast_0099 = createString("");
		temp_00FA = new StringBuilder(createString("createString("));
		value_0010->assign(1, temp_00FA->append(value_0010->get(1))->append(createString(")"))->toString());
		getValue_0094 = createString("");
	L0112: //
		if (value_0010->get(0)->equals(fieldType_0062.getValue()))
			goto L01DD;
		if (!(getValue_0094->equals(createString(""))))
			goto L01DD;
		String::__ClassInit();
		temp_0132 = new StringBuilder(String::valueOf(value_0010->get(0).getValue()));
		local_0144 = temp_0132->append(createString(":"))->append(fieldType_0062)->toString();
		switch (temp_0132->append(createString(":"))->append(fieldType_0062)->toString()->hashCode())
		{
		case (int)0x1F9A9395:
			goto L015C;
		default:
			goto L01DD;
		}
	L015C: //
		if (local_0144->equals(createString("int:bool")))
			goto L016A;
		goto L01DD;
	L016A: //
		cast_0099 = createString("");
		local_0173 = value_0010->get(1);
		switch (value_0010->get(1)->hashCode())
		{
		case (int)0x00000030:
			goto L0194;
		case (int)0x00000031:
			goto L01A2;
		default:
			goto L01C2;
		}
	L0194: //
		if (local_0173->equals(createString("0")))
			goto L01B0;
		goto L01C2;
	L01A2: //
		if (local_0173->equals(createString("1")))
			goto L01B9;
		goto L01C2;
	L01B0: //
		value_0010->assign(1, createString("false"));
		goto L01DD;
	L01B9: //
		value_0010->assign(1, createString("true"));
		goto L01DD;
	L01C2: //
		temp_01CA = new StringBuilder(createString("("));
		value_0010->assign(1, temp_01CA->append(value_0010->get(1))->append(createString(") != 0"))->toString());
	L01DD: //
		String::__ClassInit();
		temp_01E9 = new StringBuilder(String::valueOf(object_0021->get(1).getValue()));
		source->iprintln(temp_01E9->append(createString("->"))->append(instruction->getFieldName())->append(createString(" = "))->append(cast_0099)->append(value_0010->get(1))->append(getValue_0094)->append(createString(";"))->toString());
		return;
	}

	void CppExecutionContext::generatePUTSTATIC(Pointer<IndentedOutputStream> source, Pointer<InstructionPUTSTATIC> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0010;
		Pointer<String> fieldName_001F;
		Pointer<String> fqClassName_002B;
		Pointer<String> fieldType_003D;
		Pointer<JavaArray<String>> value_0068;
		Pointer<String> cast_0163;
		Pointer<String> getValue_0168;
		Pointer<JavaTypeConverter> temp_0009;
		Pointer<String> temp_0026;
		Pointer<ClassFile> temp_0033;
		Pointer<JavaTypeConverter> temp_0044;
		Pointer<String> temp_005E;
		Pointer<StringBuilder> temp_0078;
		Pointer<StringBuilder> temp_0090;
		Pointer<String> local_00A3;
		Pointer<String> local_00CF;
		Pointer<StringBuilder> temp_0115;
		Pointer<StringBuilder> temp_013A;
		Pointer<StringBuilder> temp_017A;
		Pointer<StringBuilder> temp_019A;
		temp_0009 = new JavaTypeConverter(instruction->getClassName(), true);
		className_0010 = temp_0009->getCppType();
		className_0010 = this->cppClass->simplifyType(className_0010);
		fieldName_001F = instruction->getFieldName();
		Recomp::__ClassInit();
		temp_0026 = (String*)((Recomp::simpleClassNames->get(className_0010.getValue())).getValue());
		temp_0026->checkCast(String::__thisClassStatic);
		fqClassName_002B = temp_0026;
		Recomp::__ClassInit();
		temp_0033 = (ClassFile*)((Recomp::processedClasses->get(fqClassName_002B.getValue())).getValue());
		temp_0033->checkCast(ClassFile::__thisClassStatic);
		fieldType_003D = temp_0033->getFieldType(fieldName_001F);
		temp_0044 = new JavaTypeConverter(fieldType_003D, true);
		fieldType_003D = temp_0044->getCppType();
		fieldType_003D = this->cppClass->simplifyType(fieldType_003D);
		temp_005E = (String*)((this->stack->pop()).getValue());
		temp_005E->checkCast(String::__thisClassStatic);
		value_0068 = (JavaArray<String>*)(temp_005E->split(createString("[\t]")).getValue());
		if (this->isStaticConstructor)
			goto L0087;
		String::__ClassInit();
		temp_0078 = new StringBuilder(String::valueOf(className_0010.getValue()));
		source->iprintln(temp_0078->append(createString("::__ClassInit();"))->toString());
	L0087: //
		String::__ClassInit();
		temp_0090 = new StringBuilder(String::valueOf(fieldType_003D.getValue()));
		local_00A3 = temp_0090->append(createString("\t"))->append(value_0068->get(0))->toString();
		switch (temp_0090->append(createString("\t"))->append(value_0068->get(0))->toString()->hashCode())
		{
		case (int)0x77686530:
			goto L00BC;
		default:
			goto L015E;
		}
	L00BC: //
		if (local_00A3->equals(createString("bool\tint")))
			goto L00CA;
		goto L015E;
	L00CA: //
		local_00CF = value_0068->get(1);
		switch (value_0068->get(1)->hashCode())
		{
		case (int)0x00000030:
			goto L00F0;
		case (int)0x00000031:
			goto L00FE;
		default:
			goto L0156;
		}
	L00F0: //
		if (local_00CF->equals(createString("0")))
			goto L0131;
		goto L0156;
	L00FE: //
		if (local_00CF->equals(createString("1")))
			goto L010C;
		goto L0156;
	L010C: //
		String::__ClassInit();
		temp_0115 = new StringBuilder(String::valueOf(className_0010.getValue()));
		source->iprintln(temp_0115->append(createString("::"))->append(fieldName_001F)->append(createString(" = true;"))->toString());
		goto L015D;
	L0131: //
		String::__ClassInit();
		temp_013A = new StringBuilder(String::valueOf(className_0010.getValue()));
		source->iprintln(temp_013A->append(createString("::"))->append(fieldName_001F)->append(createString(" = false;"))->toString());
		goto L015D;
	L0156: //
		Statics::__ClassInit();
		Statics::Assert(false, createString("PUTSTATIC: Non-boolean integer"));
	L015D: //
		return;
	L015E: //
		cast_0163 = createString("");
		getValue_0168 = createString("");
		if (fieldType_003D->equals(value_0068->get(0).getValue()))
			goto L0191;
		temp_017A = new StringBuilder(createString("("));
		cast_0163 = temp_017A->append(fieldType_003D)->append(createString("*)"))->toString();
		getValue_0168 = createString(".getValue()");
	L0191: //
		String::__ClassInit();
		temp_019A = new StringBuilder(String::valueOf(className_0010.getValue()));
		source->iprintln(temp_019A->append(createString("::"))->append(fieldName_001F)->append(createString(" = "))->append(cast_0163)->append(value_0068->get(1))->append(getValue_0168)->append(createString(";"))->toString());
		return;
	}

	void CppExecutionContext::generateRET(Pointer<IndentedOutputStream> source, Pointer<InstructionRET> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateRETURN(Pointer<IndentedOutputStream> source, Pointer<InstructionRETURN> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		source->iprintln(createString("return;"));
		return;
	}

	void CppExecutionContext::generateSALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionSALOAD> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateSASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionSASTORE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->notSupported(instruction.getValue());
		return;
	}

	void CppExecutionContext::generateSIPUSH(Pointer<IndentedOutputStream> source, Pointer<InstructionSIPUSH> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> stackEntry_0015;
		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("int\t"));
		stackEntry_0015 = temp_0007->append(instruction->getValue())->toString();
		this->stack->push(stackEntry_0015.getValue());
		return;
	}

	void CppExecutionContext::generateSWAP(Pointer<IndentedOutputStream> source, Pointer<InstructionSWAP> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> value1_000B;
		Pointer<String> value2_0017;
		Pointer<String> temp_0007;
		Pointer<String> temp_0012;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		value1_000B = temp_0007;
		temp_0012 = (String*)((this->stack->pop()).getValue());
		temp_0012->checkCast(String::__thisClassStatic);
		value2_0017 = temp_0012;
		this->stack->push(value1_000B.getValue());
		this->stack->push(value2_0017.getValue());
		return;
	}

	void CppExecutionContext::generateTABLESWITCH(Pointer<IndentedOutputStream> source, Pointer<InstructionTABLESWITCH> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> topOfStack_0010;
		bool isType_001B = false;
		int value_005B = 0;
		int i_005E = 0;
		Pointer<String> temp_0007;
		Pointer<StringBuilder> temp_0039;
		Pointer<StringBuilder> temp_0069;
		Pointer<StringBuilder> temp_0088;
		Pointer<StringBuilder> temp_00BB;
		temp_0007 = (String*)((this->stack->pop()).getValue());
		temp_0007->checkCast(String::__thisClassStatic);
		topOfStack_0010 = (JavaArray<String>*)(temp_0007->split(createString("[\t]")).getValue());
		isType_001B = topOfStack_0010->get(0)->equals(createString("int"));
		isType_001B = (isType_001B) | (topOfStack_0010->get(0)->equals(createString("char")));
		Statics::__ClassInit();
		Statics::Assert(isType_001B, createString("TABLESWITCH: Integer expected"));
		temp_0039 = new StringBuilder(createString("switch ("));
		source->iprintln(temp_0039->append(topOfStack_0010->get(1))->append(createString(")"))->toString());
		source->iprintln(createString("{"));
		value_005B = instruction->getFirstValue();
		i_005E = 0;
		goto L00A3;
	L0061: //
		temp_0069 = new StringBuilder(createString("case "));
		source->iprintln(temp_0069->append((value_005B) + (i_005E))->append(createString(":"))->toString());
		temp_0088 = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_0088->append(instruction->getLabel(i_005E))->append(createString(";"))->toString());
		i_005E += 1;
	L00A3: //
		if ((i_005E) < (instruction->getCaseCount()))
			goto L0061;
		source->iprintln(createString("default:"));
		temp_00BB = new StringBuilder(createString("\tgoto "));
		source->iprintln(temp_00BB->append(instruction->getDefaultLabel())->append(createString(";"))->toString());
		source->iprintln(createString("}"));
		return;
	}

	void CppExecutionContext::generateTernary(Pointer<InstructionWithLabel> instruction, Pointer<String> condition)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<TernaryOperator> ternary_0008;
		int trueJumpAddress_003A = 0;
		Pointer<JavaArray<Instruction>> instructions_0043;
		Pointer<InstructionGOTO> insnGoto_0062;
		Pointer<Instruction>  instanceOfPatternExpressionValue_004A;
		Pointer<TernaryOperator> temp_0004;
		Pointer<StringBuilder> temp_0018;
		Pointer<InstructionGOTO> temp_0054;
		Pointer<InstructionGOTO> local_0058;
		Pointer<InstructionGOTO> temp_005C;
		temp_0004 = new TernaryOperator();
		ternary_0008 = temp_0004;
		ternary_0008->condition = condition.getValue();
		temp_0018 = new StringBuilder(createString("bool\t"));
		this->stack->push(temp_0018->append(ternary_0008->condition)->toString().getValue());
		ternary_0008->falsePathAddress = instruction->getTargetAddress(0);
		trueJumpAddress_003A = (ternary_0008->falsePathAddress) - (3);
		instructions_0043 = (JavaArray<Instruction>*)(this->cppMethod->getInstructions().getValue());
		 instanceOfPatternExpressionValue_004A = instructions_0043->get(trueJumpAddress_003A);
		if (!( instanceOfPatternExpressionValue_004A->instanceOf(InstructionGOTO::__thisClassStatic)))
			goto L0075;
		temp_0054 = (InstructionGOTO*)(( instanceOfPatternExpressionValue_004A).getValue());
		temp_0054->checkCast(InstructionGOTO::__thisClassStatic);
		local_0058 = temp_0054;
		temp_005C = (InstructionGOTO*)(( instanceOfPatternExpressionValue_004A).getValue());
		temp_005C->checkCast(InstructionGOTO::__thisClassStatic);
		if ((temp_0054) != (temp_005C))
			goto L0075;
		ternary_0008->endAddress = insnGoto_0062->getTargetAddress(0);
		ternary_0008->endOfTruePath = trueJumpAddress_003A;
		goto L007C;
	L0075: //
		Statics::__ClassInit();
		Statics::Assert(false, createString("GOTO expected at the end of true path"));
	L007C: //
		this->ternaryStack->push(ternary_0008.getValue());
		return;
	}

	void CppExecutionContext::generateWIDE(Pointer<IndentedOutputStream> source, Pointer<InstructionWIDE> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->generate(source, instruction->getNestedInstruction());
		return;
	}

	void CppExecutionContext::generateXLOAD(Pointer<IndentedOutputStream> source, Pointer<Instruction> instruction, Pointer<String> type)
	{
		UsageCounterMaintainer maintainer(this, true);

		int index_0006 = 0;
		Pointer<String> insnType_0014;
		Pointer<LocalVariable> local_0068;
		Pointer<StringBuilder> temp_0027;
		Pointer<StringBuilder> temp_004D;
		Pointer<StringBuilder> temp_0079;
		Pointer<StringBuilder> temp_009F;
		Pointer<StringBuilder> temp_00D6;
		index_0006 = instruction->getIndex();
		insnType_0014 = instruction->getClass()->getSimpleName()->substring(8);
		String::__ClassInit();
		temp_0027 = new StringBuilder(String::valueOf(insnType_0014.getValue()));
		Statics::__ClassInit();
		Statics::Assert(((((index_0006) >= 0) ? (1) : (0))) != 0, temp_0027->append(createString(": index out of range"))->toString());
		String::__ClassInit();
		temp_004D = new StringBuilder(String::valueOf(insnType_0014.getValue()));
		Statics::__ClassInit();
		Statics::Assert(((((index_0006) < (this->maxLocals)) ? (1) : (0))) != 0, temp_004D->append(createString(": index out of range"))->toString());
		local_0068 = this->locals->get(index_0006, instruction);
		temp_0079 = new StringBuilder(createString("Local at "));
		Statics::__ClassInit();
		Statics::Assert(((((local_0068).getValue() != nullptr) ? (1) : (0))) != 0, temp_0079->append(index_0006)->append(createString(" is not available"))->toString());
		String::__ClassInit();
		temp_009F = new StringBuilder(String::valueOf(insnType_0014.getValue()));
		Statics::__ClassInit();
		Statics::Assert(local_0068->getType()->equals(type.getValue()), temp_009F->append(createString(": Bad type \'"))->append(local_0068->getType())->append(createString(", "))->append(type)->append(createString(" expected"))->toString());
		String::__ClassInit();
		temp_00D6 = new StringBuilder(String::valueOf(local_0068->getType().getValue()));
		this->stack->push(temp_00D6->append(createString("\t"))->append(local_0068->getName())->toString().getValue());
		return;
	}

	void CppExecutionContext::generateXRETURN(Pointer<IndentedOutputStream> source, Pointer<Instruction> instruction, Pointer<String> type)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> insnType_000E;
		Pointer<JavaArray<String>> value_001F;
		Pointer<String> temp_0015;
		Pointer<StringBuilder> temp_0030;
		Pointer<StringBuilder> temp_005E;
		insnType_000E = instruction->getClass()->getSimpleName()->substring(8);
		temp_0015 = (String*)((this->stack->pop()).getValue());
		temp_0015->checkCast(String::__thisClassStatic);
		value_001F = (JavaArray<String>*)(temp_0015->split(createString("[\t]")).getValue());
		String::__ClassInit();
		temp_0030 = new StringBuilder(String::valueOf(insnType_000E.getValue()));
		Statics::__ClassInit();
		Statics::Assert(value_001F->get(0)->equals(type.getValue()), temp_0030->append(createString(": Type mismatch, "))->append(value_001F->get(0))->append(createString(" value, "))->append(type)->append(createString(" expected"))->toString());
		temp_005E = new StringBuilder(createString("return "));
		source->iprintln(temp_005E->append(value_001F->get(1))->append(createString(";"))->toString());
		return;
	}

	void CppExecutionContext::generateXSTORE(Pointer<IndentedOutputStream> source, Pointer<Instruction> instruction, Pointer<String> type)
	{
		UsageCounterMaintainer maintainer(this, true);

		int index_0006 = 0;
		Pointer<String> insnType_0014;
		Pointer<LocalVariable> local_0044;
		Pointer<JavaArray<String>> topOfStack_0055;
		Pointer<String> temp_004B;
		Pointer<StringBuilder> temp_0067;
		Pointer<StringBuilder> temp_00A3;
		Pointer<StringBuilder> temp_00BF;
		index_0006 = instruction->getIndex();
		insnType_0014 = instruction->getClass()->getSimpleName()->substring(8);
		Statics::__ClassInit();
		Statics::Assert(((((index_0006) >= 0) ? (1) : (0))) != 0, createString("Local index out of range"));
		Statics::__ClassInit();
		Statics::Assert(((((index_0006) < (this->maxLocals)) ? (1) : (0))) != 0, createString("Local index out of range"));
		local_0044 = this->locals->get(index_0006, instruction);
		temp_004B = (String*)((this->stack->pop()).getValue());
		temp_004B->checkCast(String::__thisClassStatic);
		topOfStack_0055 = (JavaArray<String>*)(temp_004B->split(createString("[\t]")).getValue());
		String::__ClassInit();
		temp_0067 = new StringBuilder(String::valueOf(insnType_0014.getValue()));
		Statics::__ClassInit();
		Statics::Assert(local_0044->getType()->equals(type.getValue()), temp_0067->append(createString(": Bad type \'"))->append(local_0044->getType())->append(createString(", "))->append(type)->append(createString(" expected"))->toString());
		String::__ClassInit();
		temp_00A3 = new StringBuilder(String::valueOf(insnType_0014.getValue()));
		Statics::__ClassInit();
		Statics::Assert(local_0044->getType()->equals(topOfStack_0055->get(0).getValue()), temp_00A3->append(createString(": Type mismatch"))->toString());
		String::__ClassInit();
		temp_00BF = new StringBuilder(String::valueOf(local_0044->getName().getValue()));
		source->iprintln(temp_00BF->append(createString(" = "))->append(topOfStack_0055->get(1))->append(createString(";"))->toString());
		return;
	}

	void CppExecutionContext::notSupported(Pointer<Instruction> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> opcode_000D;
		Pointer<StringBuilder> temp_0015;
		opcode_000D = instruction->getClass()->getSimpleName()->substring(11);
		temp_0015 = new StringBuilder(createString("Instruction "));
		Statics::__ClassInit();
		Statics::Assert(false, temp_0015->append(opcode_000D)->append(createString(" execution not supported"))->toString());
		return;
	}

}
