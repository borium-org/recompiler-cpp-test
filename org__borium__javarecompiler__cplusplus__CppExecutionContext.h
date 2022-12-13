#pragma once

#include "org__borium__javarecompiler__classfile__ExecutionContext.h"

namespace java::io
{
	class PrintStream;
}

namespace java::lang
{
	class Character;
	class Class;
	class Integer;
	class Object;
	class RuntimeException;
	class String;
	class StringBuilder;
	class System;
}

namespace java::util
{
	template <class A> class ArrayList;
	template <class A, class B> class HashMap;
	template <class A> class Stack;
}

namespace org::borium::javarecompiler
{
	class Recomp;
	class Statics;
}

namespace org::borium::javarecompiler::classfile
{
	class ClassFile;
	class ClassMethod;
	class ClassTypeSimplifier;
	class ExecutionContext;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::attribute
{
	class AttributeCode;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class Constant;
	class ConstantClassInfo;
	class ConstantDouble;
	class ConstantFloat;
	class ConstantInteger;
	class ConstantStringInfo;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
	class InstructionAALOAD;
	class InstructionAASTORE;
	class InstructionACONST_NULL;
	class InstructionALOAD;
	class InstructionANEWARRAY;
	class InstructionARETURN;
	class InstructionARRAYLENGTH;
	class InstructionASTORE;
	class InstructionATHROW;
	class InstructionBALOAD;
	class InstructionBASTORE;
	class InstructionBIPUSH;
	class InstructionCALOAD;
	class InstructionCASTORE;
	class InstructionCHECKCAST;
	class InstructionD2F;
	class InstructionD2I;
	class InstructionD2L;
	class InstructionDADD;
	class InstructionDALOAD;
	class InstructionDASTORE;
	class InstructionDCMPG;
	class InstructionDCMPL;
	class InstructionDCONST;
	class InstructionDDIV;
	class InstructionDLOAD;
	class InstructionDMUL;
	class InstructionDNEG;
	class InstructionDREM;
	class InstructionDRETURN;
	class InstructionDSTORE;
	class InstructionDSUB;
	class InstructionDUP;
	class InstructionDUP2;
	class InstructionDUP2_X1;
	class InstructionDUP2_X2;
	class InstructionDUP_X1;
	class InstructionDUP_X2;
	class InstructionF2D;
	class InstructionF2I;
	class InstructionF2L;
	class InstructionFADD;
	class InstructionFALOAD;
	class InstructionFASTORE;
	class InstructionFCMPG;
	class InstructionFCMPL;
	class InstructionFCONST;
	class InstructionFDIV;
	class InstructionFLOAD;
	class InstructionFMUL;
	class InstructionFNEG;
	class InstructionFREM;
	class InstructionFRETURN;
	class InstructionFSTORE;
	class InstructionFSUB;
	class InstructionGETFIELD;
	class InstructionGETSTATIC;
	class InstructionGOTO;
	class InstructionGOTO_W;
	class InstructionI2B;
	class InstructionI2C;
	class InstructionI2D;
	class InstructionI2F;
	class InstructionI2L;
	class InstructionI2S;
	class InstructionIADD;
	class InstructionIALOAD;
	class InstructionIAND;
	class InstructionIASTORE;
	class InstructionICONST;
	class InstructionIDIV;
	class InstructionIFEQ;
	class InstructionIFGE;
	class InstructionIFGT;
	class InstructionIFLE;
	class InstructionIFLT;
	class InstructionIFNE;
	class InstructionIFNONNULL;
	class InstructionIFNULL;
	class InstructionIF_ACMPEQ;
	class InstructionIF_ACMPNE;
	class InstructionIF_ICMPEQ;
	class InstructionIF_ICMPGE;
	class InstructionIF_ICMPGT;
	class InstructionIF_ICMPLE;
	class InstructionIF_ICMPLT;
	class InstructionIF_ICMPNE;
	class InstructionIINC;
	class InstructionILOAD;
	class InstructionIMUL;
	class InstructionINEG;
	class InstructionINSTANCEOF;
	class InstructionINVOKEDYNAMIC;
	class InstructionINVOKEINTERFACE;
	class InstructionINVOKESPECIAL;
	class InstructionINVOKESTATIC;
	class InstructionINVOKEVIRTUAL;
	class InstructionIOR;
	class InstructionIREM;
	class InstructionIRETURN;
	class InstructionISHL;
	class InstructionISHR;
	class InstructionISTORE;
	class InstructionISUB;
	class InstructionIUSHR;
	class InstructionIXOR;
	class InstructionJSR;
	class InstructionJSR_W;
	class InstructionL2D;
	class InstructionL2F;
	class InstructionL2I;
	class InstructionLADD;
	class InstructionLALOAD;
	class InstructionLAND;
	class InstructionLASTORE;
	class InstructionLCMP;
	class InstructionLCONST;
	class InstructionLDC;
	class InstructionLDC2_W;
	class InstructionLDC_W;
	class InstructionLDIV;
	class InstructionLLOAD;
	class InstructionLMUL;
	class InstructionLNEG;
	class InstructionLOOKUPSWITCH;
	class InstructionLOR;
	class InstructionLREM;
	class InstructionLRETURN;
	class InstructionLSHL;
	class InstructionLSHR;
	class InstructionLSTORE;
	class InstructionLSUB;
	class InstructionLUSHR;
	class InstructionLXOR;
	class InstructionMONITORENTER;
	class InstructionMONITOREXIT;
	class InstructionMULTIANEWARRAY;
	class InstructionNEW;
	class InstructionNEWARRAY;
	class InstructionNOP;
	class InstructionPOP;
	class InstructionPOP2;
	class InstructionPUTFIELD;
	class InstructionPUTSTATIC;
	class InstructionRET;
	class InstructionRETURN;
	class InstructionSALOAD;
	class InstructionSASTORE;
	class InstructionSIPUSH;
	class InstructionSWAP;
	class InstructionTABLESWITCH;
	class InstructionWIDE;
	class InstructionWithLabel;
}

namespace org::borium::javarecompiler::cplusplus
{
	class CppClass;
	class CppMethod;
	class JavaTypeConverter;
	class LocalVariable;
	class LocalVariables;
	class TernaryOperator;
}

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

	class CppExecutionContext : public ExecutionContext
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<String> cppType;
		Pointer<String> classType;
		Pointer<CppClass> cppClass;
		Pointer<CppMethod> cppMethod;
		Pointer<LocalVariables> locals;
		int codeSize;
		bool isStaticConstructor;
		Pointer<Stack<TernaryOperator>> ternaryStack;

		static void __ClassInit();
		CppExecutionContext(Pointer<CppMethod> cppMethod, Pointer<CppClass> cppClass, Pointer<ClassMethod> javaMethod);
		virtual void generate(Pointer<IndentedOutputStream> source, Pointer<Instruction> instruction);
		virtual int getCodeSize();
		virtual Pointer<LocalVariable> getLocalVariable(int index, int address);
		virtual Pointer<ArrayList<LocalVariable>> getLocalVariables();
		virtual bool hasLabel(int address);
		virtual Pointer<String> typeSimplifier(Pointer<String> type);
		virtual Pointer<String> addTemplateParameters(Pointer<String> className);
		virtual Pointer<ClassFile> findClassByName(Pointer<String> simpleClassName);
		virtual void generateAALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionAALOAD> instruction);
		virtual void generateAASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionAASTORE> instruction);
		virtual void generateACONST_NULL(Pointer<IndentedOutputStream> source, Pointer<InstructionACONST_NULL> instruction);
		virtual void generateALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionALOAD> instruction);
		virtual void generateANEWARRAY(Pointer<IndentedOutputStream> source, Pointer<InstructionANEWARRAY> instruction);
		virtual void generateARETURN(Pointer<IndentedOutputStream> source, Pointer<InstructionARETURN> instruction);
		virtual void generateARRAYLENGTH(Pointer<IndentedOutputStream> source, Pointer<InstructionARRAYLENGTH> instruction);
		virtual void generateASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionASTORE> instruction);
		virtual void generateATHROW(Pointer<IndentedOutputStream> source, Pointer<InstructionATHROW> instruction);
		virtual void generateBALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionBALOAD> instruction);
		virtual void generateBASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionBASTORE> instruction);
		virtual void generateBinaryOp(Pointer<IndentedOutputStream> source, Pointer<Instruction> instruction, Pointer<String> type, Pointer<String> op);
		virtual void generateBIPUSH(Pointer<IndentedOutputStream> source, Pointer<InstructionBIPUSH> instruction);
		virtual void generateCALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionCALOAD> instruction);
		virtual void generateCASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionCASTORE> instruction);
		virtual void generateCHECKCAST(Pointer<IndentedOutputStream> source, Pointer<InstructionCHECKCAST> instruction);
		virtual void generateConversion(Pointer<Instruction> instruction, Pointer<String> typeFrom, Pointer<String> typeTo);
		virtual void generateD2F(Pointer<IndentedOutputStream> source, Pointer<InstructionD2F> instruction);
		virtual void generateD2I(Pointer<IndentedOutputStream> source, Pointer<InstructionD2I> instruction);
		virtual void generateD2L(Pointer<IndentedOutputStream> source, Pointer<InstructionD2L> instruction);
		virtual void generateDADD(Pointer<IndentedOutputStream> source, Pointer<InstructionDADD> instruction);
		virtual void generateDALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionDALOAD> instruction);
		virtual void generateDASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionDASTORE> instruction);
		virtual void generateDCMPG(Pointer<IndentedOutputStream> source, Pointer<InstructionDCMPG> instruction);
		virtual void generateDCMPL(Pointer<IndentedOutputStream> source, Pointer<InstructionDCMPL> instruction);
		virtual void generateDCONST(Pointer<IndentedOutputStream> source, Pointer<InstructionDCONST> instruction);
		virtual void generateDDIV(Pointer<IndentedOutputStream> source, Pointer<InstructionDDIV> instruction);
		virtual void generateDLOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionDLOAD> instruction);
		virtual void generateDMUL(Pointer<IndentedOutputStream> source, Pointer<InstructionDMUL> instruction);
		virtual void generateDNEG(Pointer<IndentedOutputStream> source, Pointer<InstructionDNEG> instruction);
		virtual void generateDREM(Pointer<IndentedOutputStream> source, Pointer<InstructionDREM> instruction);
		virtual void generateDRETURN(Pointer<IndentedOutputStream> source, Pointer<InstructionDRETURN> instruction);
		virtual void generateDSTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionDSTORE> instruction);
		virtual void generateDSUB(Pointer<IndentedOutputStream> source, Pointer<InstructionDSUB> instruction);
		virtual void generateDUP(Pointer<IndentedOutputStream> source, Pointer<InstructionDUP> instruction);
		virtual void generateDUP_X1(Pointer<IndentedOutputStream> source, Pointer<InstructionDUP_X1> instruction);
		virtual void generateDUP_X2(Pointer<IndentedOutputStream> source, Pointer<InstructionDUP_X2> instruction);
		virtual void generateDUP2(Pointer<IndentedOutputStream> source, Pointer<InstructionDUP2> instruction);
		virtual void generateDUP2_X1(Pointer<IndentedOutputStream> source, Pointer<InstructionDUP2_X1> instruction);
		virtual void generateDUP2_X2(Pointer<IndentedOutputStream> source, Pointer<InstructionDUP2_X2> instruction);
		virtual void generateF2D(Pointer<IndentedOutputStream> source, Pointer<InstructionF2D> instruction);
		virtual void generateF2I(Pointer<IndentedOutputStream> source, Pointer<InstructionF2I> instruction);
		virtual void generateF2L(Pointer<IndentedOutputStream> source, Pointer<InstructionF2L> instruction);
		virtual void generateFADD(Pointer<IndentedOutputStream> source, Pointer<InstructionFADD> instruction);
		virtual void generateFALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionFALOAD> instruction);
		virtual void generateFASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionFASTORE> instruction);
		virtual void generateFCMPG(Pointer<IndentedOutputStream> source, Pointer<InstructionFCMPG> instruction);
		virtual void generateFCMPL(Pointer<IndentedOutputStream> source, Pointer<InstructionFCMPL> instruction);
		virtual void generateFCONST(Pointer<IndentedOutputStream> source, Pointer<InstructionFCONST> instruction);
		virtual void generateFDIV(Pointer<IndentedOutputStream> source, Pointer<InstructionFDIV> instruction);
		virtual void generateFLOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionFLOAD> instruction);
		virtual void generateFMUL(Pointer<IndentedOutputStream> source, Pointer<InstructionFMUL> instruction);
		virtual void generateFNEG(Pointer<IndentedOutputStream> source, Pointer<InstructionFNEG> instruction);
		virtual void generateFREM(Pointer<IndentedOutputStream> source, Pointer<InstructionFREM> instruction);
		virtual void generateFRETURN(Pointer<IndentedOutputStream> source, Pointer<InstructionFRETURN> instruction);
		virtual void generateFSTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionFSTORE> instruction);
		virtual void generateFSUB(Pointer<IndentedOutputStream> source, Pointer<InstructionFSUB> instruction);
		virtual void generateGETFIELD(Pointer<IndentedOutputStream> source, Pointer<InstructionGETFIELD> instruction);
		virtual void generateGETSTATIC(Pointer<IndentedOutputStream> source, Pointer<InstructionGETSTATIC> instruction);
		virtual void generateGOTO(Pointer<IndentedOutputStream> source, Pointer<InstructionGOTO> instruction);
		virtual void generateGOTO_W(Pointer<IndentedOutputStream> source, Pointer<InstructionGOTO_W> instruction);
		virtual void generateI2B(Pointer<IndentedOutputStream> source, Pointer<InstructionI2B> instruction);
		virtual void generateI2C(Pointer<IndentedOutputStream> source, Pointer<InstructionI2C> instruction);
		virtual void generateI2D(Pointer<IndentedOutputStream> source, Pointer<InstructionI2D> instruction);
		virtual void generateI2F(Pointer<IndentedOutputStream> source, Pointer<InstructionI2F> instruction);
		virtual void generateI2L(Pointer<IndentedOutputStream> source, Pointer<InstructionI2L> instruction);
		virtual void generateI2S(Pointer<IndentedOutputStream> source, Pointer<InstructionI2S> instruction);
		virtual void generateIADD(Pointer<IndentedOutputStream> source, Pointer<InstructionIADD> instruction);
		virtual void generateIALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionIALOAD> instruction);
		virtual void generateIAND(Pointer<IndentedOutputStream> source, Pointer<InstructionIAND> instruction);
		virtual void generateIASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionIASTORE> instruction);
		virtual void generateICONST(Pointer<IndentedOutputStream> source, Pointer<InstructionICONST> instruction);
		virtual void generateIDIV(Pointer<IndentedOutputStream> source, Pointer<InstructionIDIV> instruction);
		virtual void generateIF_ACMPEQ(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ACMPEQ> instruction);
		virtual void generateIF_ACMPNE(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ACMPNE> instruction);
		virtual void generateIF_ICMPEQ(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ICMPEQ> instruction);
		virtual void generateIF_ICMPGE(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ICMPGE> instruction);
		virtual void generateIF_ICMPGT(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ICMPGT> instruction);
		virtual void generateIF_ICMPLE(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ICMPLE> instruction);
		virtual void generateIF_ICMPLT(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ICMPLT> instruction);
		virtual void generateIF_ICMPNE(Pointer<IndentedOutputStream> source, Pointer<InstructionIF_ICMPNE> instruction);
		virtual void generateIFEQ(Pointer<IndentedOutputStream> source, Pointer<InstructionIFEQ> instruction);
		virtual void generateIFGE(Pointer<IndentedOutputStream> source, Pointer<InstructionIFGE> instruction);
		virtual void generateIFGT(Pointer<IndentedOutputStream> source, Pointer<InstructionIFGT> instruction);
		virtual void generateIFLE(Pointer<IndentedOutputStream> source, Pointer<InstructionIFLE> instruction);
		virtual void generateIFLT(Pointer<IndentedOutputStream> source, Pointer<InstructionIFLT> instruction);
		virtual void generateIFNE(Pointer<IndentedOutputStream> source, Pointer<InstructionIFNE> instruction);
		virtual void generateIFNONNULL(Pointer<IndentedOutputStream> source, Pointer<InstructionIFNONNULL> instruction);
		virtual void generateIFNULL(Pointer<IndentedOutputStream> source, Pointer<InstructionIFNULL> instruction);
		virtual void generateIINC(Pointer<IndentedOutputStream> source, Pointer<InstructionIINC> instruction);
		virtual void generateILOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionILOAD> instruction);
		virtual void generateIMUL(Pointer<IndentedOutputStream> source, Pointer<InstructionIMUL> instruction);
		virtual void generateINEG(Pointer<IndentedOutputStream> source, Pointer<InstructionINEG> instruction);
		virtual void generateINSTANCEOF(Pointer<IndentedOutputStream> source, Pointer<InstructionINSTANCEOF> instruction);
		virtual void generateINVOKEDYNAMIC(Pointer<IndentedOutputStream> source, Pointer<InstructionINVOKEDYNAMIC> instruction);
		virtual void generateINVOKEINTERFACE(Pointer<IndentedOutputStream> source, Pointer<InstructionINVOKEINTERFACE> instruction);
		virtual void generateINVOKESPECIAL(Pointer<IndentedOutputStream> source, Pointer<InstructionINVOKESPECIAL> instruction);
		virtual void generateINVOKESTATIC(Pointer<IndentedOutputStream> source, Pointer<InstructionINVOKESTATIC> instruction);
		virtual void generateINVOKEVIRTUAL(Pointer<IndentedOutputStream> source, Pointer<InstructionINVOKEVIRTUAL> instruction);
		virtual void generateIOR(Pointer<IndentedOutputStream> source, Pointer<InstructionIOR> instruction);
		virtual void generateIREM(Pointer<IndentedOutputStream> source, Pointer<InstructionIREM> instruction);
		virtual void generateIRETURN(Pointer<IndentedOutputStream> source, Pointer<InstructionIRETURN> instruction);
		virtual void generateISHL(Pointer<IndentedOutputStream> source, Pointer<InstructionISHL> instruction);
		virtual void generateISHR(Pointer<IndentedOutputStream> source, Pointer<InstructionISHR> instruction);
		virtual void generateISTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionISTORE> instruction);
		virtual void generateISUB(Pointer<IndentedOutputStream> source, Pointer<InstructionISUB> instruction);
		virtual void generateIUSHR(Pointer<IndentedOutputStream> source, Pointer<InstructionIUSHR> instruction);
		virtual void generateIXOR(Pointer<IndentedOutputStream> source, Pointer<InstructionIXOR> instruction);
		virtual void generateJSR(Pointer<IndentedOutputStream> source, Pointer<InstructionJSR> instruction);
		virtual void generateJSR_W(Pointer<IndentedOutputStream> source, Pointer<InstructionJSR_W> instruction);
		virtual void generateL2D(Pointer<IndentedOutputStream> source, Pointer<InstructionL2D> instruction);
		virtual void generateL2F(Pointer<IndentedOutputStream> source, Pointer<InstructionL2F> instruction);
		virtual void generateL2I(Pointer<IndentedOutputStream> source, Pointer<InstructionL2I> instruction);
		virtual void generateLADD(Pointer<IndentedOutputStream> source, Pointer<InstructionLADD> instruction);
		virtual void generateLALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionLALOAD> instruction);
		virtual void generateLAND(Pointer<IndentedOutputStream> source, Pointer<InstructionLAND> instruction);
		virtual void generateLASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionLASTORE> instruction);
		virtual void generateLCMP(Pointer<IndentedOutputStream> source, Pointer<InstructionLCMP> instruction);
		virtual void generateLCONST(Pointer<IndentedOutputStream> source, Pointer<InstructionLCONST> instruction);
		virtual void generateLDC(Pointer<IndentedOutputStream> source, Pointer<InstructionLDC> instruction);
		virtual void generateLDC_W(Pointer<IndentedOutputStream> source, Pointer<InstructionLDC_W> instruction);
		virtual void generateLDC2_W(Pointer<IndentedOutputStream> source, Pointer<InstructionLDC2_W> instruction);
		virtual void generateLDIV(Pointer<IndentedOutputStream> source, Pointer<InstructionLDIV> instruction);
		virtual void generateLLOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionLLOAD> instruction);
		virtual void generateLMUL(Pointer<IndentedOutputStream> source, Pointer<InstructionLMUL> instruction);
		virtual void generateLNEG(Pointer<IndentedOutputStream> source, Pointer<InstructionLNEG> instruction);
		virtual void generateLoadConstant(Pointer<Constant> constant);
		virtual void generateLOOKUPSWITCH(Pointer<IndentedOutputStream> source, Pointer<InstructionLOOKUPSWITCH> instruction);
		virtual void generateLOR(Pointer<IndentedOutputStream> source, Pointer<InstructionLOR> instruction);
		virtual void generateLREM(Pointer<IndentedOutputStream> source, Pointer<InstructionLREM> instruction);
		virtual void generateLRETURN(Pointer<IndentedOutputStream> source, Pointer<InstructionLRETURN> instruction);
		virtual void generateLSHL(Pointer<IndentedOutputStream> source, Pointer<InstructionLSHL> instruction);
		virtual void generateLSHR(Pointer<IndentedOutputStream> source, Pointer<InstructionLSHR> instruction);
		virtual void generateLSTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionLSTORE> instruction);
		virtual void generateLSUB(Pointer<IndentedOutputStream> source, Pointer<InstructionLSUB> instruction);
		virtual void generateLUSHR(Pointer<IndentedOutputStream> source, Pointer<InstructionLUSHR> instruction);
		virtual void generateLXOR(Pointer<IndentedOutputStream> source, Pointer<InstructionLXOR> instruction);
		virtual void generateMONITORENTER(Pointer<IndentedOutputStream> source, Pointer<InstructionMONITORENTER> instruction);
		virtual void generateMONITOREXIT(Pointer<IndentedOutputStream> source, Pointer<InstructionMONITOREXIT> instruction);
		virtual void generateMULTIANEWARRAY(Pointer<IndentedOutputStream> source, Pointer<InstructionMULTIANEWARRAY> instruction);
		virtual void generateNEW(Pointer<IndentedOutputStream> source, Pointer<InstructionNEW> instruction);
		virtual void generateNEWARRAY(Pointer<IndentedOutputStream> source, Pointer<InstructionNEWARRAY> instruction);
		virtual void generateNOP(Pointer<IndentedOutputStream> source, Pointer<InstructionNOP> instruction);
		virtual Pointer<JavaArray<String>> generateParameters(Pointer<JavaArray<String>> parameterTypes, int parameterCount);
		virtual void generatePOP(Pointer<IndentedOutputStream> source, Pointer<InstructionPOP> instruction);
		virtual void generatePOP2(Pointer<IndentedOutputStream> source, Pointer<InstructionPOP2> instruction);
		virtual void generatePUTFIELD(Pointer<IndentedOutputStream> source, Pointer<InstructionPUTFIELD> instruction);
		virtual void generatePUTSTATIC(Pointer<IndentedOutputStream> source, Pointer<InstructionPUTSTATIC> instruction);
		virtual void generateRET(Pointer<IndentedOutputStream> source, Pointer<InstructionRET> instruction);
		virtual void generateRETURN(Pointer<IndentedOutputStream> source, Pointer<InstructionRETURN> instruction);
		virtual void generateSALOAD(Pointer<IndentedOutputStream> source, Pointer<InstructionSALOAD> instruction);
		virtual void generateSASTORE(Pointer<IndentedOutputStream> source, Pointer<InstructionSASTORE> instruction);
		virtual void generateSIPUSH(Pointer<IndentedOutputStream> source, Pointer<InstructionSIPUSH> instruction);
		virtual void generateSWAP(Pointer<IndentedOutputStream> source, Pointer<InstructionSWAP> instruction);
		virtual void generateTABLESWITCH(Pointer<IndentedOutputStream> source, Pointer<InstructionTABLESWITCH> instruction);
		virtual void generateTernary(Pointer<InstructionWithLabel> instruction, Pointer<String> condition);
		virtual void generateWIDE(Pointer<IndentedOutputStream> source, Pointer<InstructionWIDE> instruction);
		virtual void generateXLOAD(Pointer<IndentedOutputStream> source, Pointer<Instruction> instruction, Pointer<String> type);
		virtual void generateXRETURN(Pointer<IndentedOutputStream> source, Pointer<Instruction> instruction, Pointer<String> type);
		virtual void generateXSTORE(Pointer<IndentedOutputStream> source, Pointer<Instruction> instruction, Pointer<String> type);
		virtual void notSupported(Pointer<Instruction> instruction);
	};

}
