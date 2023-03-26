#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/LTC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/LTC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=C:/Users/Mieko/Downloads/Car_Project/uart.c C:/Users/Mieko/Downloads/Car_Project/main.c C:/Users/Mieko/Downloads/Car_Project/car_tracking.c C:/Users/Mieko/Downloads/Car_Project/adc.c C:/Users/Mieko/Downloads/Car_Project/utils.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1266796427/uart.o ${OBJECTDIR}/_ext/1266796427/main.o ${OBJECTDIR}/_ext/1266796427/car_tracking.o ${OBJECTDIR}/_ext/1266796427/adc.o ${OBJECTDIR}/_ext/1266796427/utils.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1266796427/uart.o.d ${OBJECTDIR}/_ext/1266796427/main.o.d ${OBJECTDIR}/_ext/1266796427/car_tracking.o.d ${OBJECTDIR}/_ext/1266796427/adc.o.d ${OBJECTDIR}/_ext/1266796427/utils.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1266796427/uart.o ${OBJECTDIR}/_ext/1266796427/main.o ${OBJECTDIR}/_ext/1266796427/car_tracking.o ${OBJECTDIR}/_ext/1266796427/adc.o ${OBJECTDIR}/_ext/1266796427/utils.o

# Source Files
SOURCEFILES=C:/Users/Mieko/Downloads/Car_Project/uart.c C:/Users/Mieko/Downloads/Car_Project/main.c C:/Users/Mieko/Downloads/Car_Project/car_tracking.c C:/Users/Mieko/Downloads/Car_Project/adc.c C:/Users/Mieko/Downloads/Car_Project/utils.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/LTC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F4013
MP_LINKER_FILE_OPTION=,--script=p30F4013.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1266796427/uart.o: C:/Users/Mieko/Downloads/Car_Project/uart.c  .generated_files/flags/default/a5e1fc532cea8e04e1ed5c03798f789866d4a413 .generated_files/flags/default/74b34707da22605293d6311696ae0a4a34fb9101
	@${MKDIR} "${OBJECTDIR}/_ext/1266796427" 
	@${RM} ${OBJECTDIR}/_ext/1266796427/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1266796427/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/Mieko/Downloads/Car_Project/uart.c  -o ${OBJECTDIR}/_ext/1266796427/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1266796427/uart.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1266796427/main.o: C:/Users/Mieko/Downloads/Car_Project/main.c  .generated_files/flags/default/297b64542cdf4f16059fa2f9fc1ddd31e247268f .generated_files/flags/default/74b34707da22605293d6311696ae0a4a34fb9101
	@${MKDIR} "${OBJECTDIR}/_ext/1266796427" 
	@${RM} ${OBJECTDIR}/_ext/1266796427/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1266796427/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/Mieko/Downloads/Car_Project/main.c  -o ${OBJECTDIR}/_ext/1266796427/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1266796427/main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1266796427/car_tracking.o: C:/Users/Mieko/Downloads/Car_Project/car_tracking.c  .generated_files/flags/default/ce3223b83cd54f0982facb6b9f88869d127c2ac6 .generated_files/flags/default/74b34707da22605293d6311696ae0a4a34fb9101
	@${MKDIR} "${OBJECTDIR}/_ext/1266796427" 
	@${RM} ${OBJECTDIR}/_ext/1266796427/car_tracking.o.d 
	@${RM} ${OBJECTDIR}/_ext/1266796427/car_tracking.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/Mieko/Downloads/Car_Project/car_tracking.c  -o ${OBJECTDIR}/_ext/1266796427/car_tracking.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1266796427/car_tracking.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1266796427/adc.o: C:/Users/Mieko/Downloads/Car_Project/adc.c  .generated_files/flags/default/cb9da74247762382e33445ff5040aeb2506f1a84 .generated_files/flags/default/74b34707da22605293d6311696ae0a4a34fb9101
	@${MKDIR} "${OBJECTDIR}/_ext/1266796427" 
	@${RM} ${OBJECTDIR}/_ext/1266796427/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1266796427/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/Mieko/Downloads/Car_Project/adc.c  -o ${OBJECTDIR}/_ext/1266796427/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1266796427/adc.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1266796427/utils.o: C:/Users/Mieko/Downloads/Car_Project/utils.c  .generated_files/flags/default/89628c063c3b29032aeec85730d8da553a42321 .generated_files/flags/default/74b34707da22605293d6311696ae0a4a34fb9101
	@${MKDIR} "${OBJECTDIR}/_ext/1266796427" 
	@${RM} ${OBJECTDIR}/_ext/1266796427/utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1266796427/utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/Mieko/Downloads/Car_Project/utils.c  -o ${OBJECTDIR}/_ext/1266796427/utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1266796427/utils.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
else
${OBJECTDIR}/_ext/1266796427/uart.o: C:/Users/Mieko/Downloads/Car_Project/uart.c  .generated_files/flags/default/db4daf8a249b04e2280af81da393ffae32805a75 .generated_files/flags/default/74b34707da22605293d6311696ae0a4a34fb9101
	@${MKDIR} "${OBJECTDIR}/_ext/1266796427" 
	@${RM} ${OBJECTDIR}/_ext/1266796427/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1266796427/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/Mieko/Downloads/Car_Project/uart.c  -o ${OBJECTDIR}/_ext/1266796427/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1266796427/uart.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1266796427/main.o: C:/Users/Mieko/Downloads/Car_Project/main.c  .generated_files/flags/default/fa57c246c097fcde1f613debc6d4bd011eb0ec36 .generated_files/flags/default/74b34707da22605293d6311696ae0a4a34fb9101
	@${MKDIR} "${OBJECTDIR}/_ext/1266796427" 
	@${RM} ${OBJECTDIR}/_ext/1266796427/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1266796427/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/Mieko/Downloads/Car_Project/main.c  -o ${OBJECTDIR}/_ext/1266796427/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1266796427/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1266796427/car_tracking.o: C:/Users/Mieko/Downloads/Car_Project/car_tracking.c  .generated_files/flags/default/276827d06a2840174c239db8d6be1b4a15563e2b .generated_files/flags/default/74b34707da22605293d6311696ae0a4a34fb9101
	@${MKDIR} "${OBJECTDIR}/_ext/1266796427" 
	@${RM} ${OBJECTDIR}/_ext/1266796427/car_tracking.o.d 
	@${RM} ${OBJECTDIR}/_ext/1266796427/car_tracking.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/Mieko/Downloads/Car_Project/car_tracking.c  -o ${OBJECTDIR}/_ext/1266796427/car_tracking.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1266796427/car_tracking.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1266796427/adc.o: C:/Users/Mieko/Downloads/Car_Project/adc.c  .generated_files/flags/default/cbf30a5b30d82158e3fabb4544597547303ba830 .generated_files/flags/default/74b34707da22605293d6311696ae0a4a34fb9101
	@${MKDIR} "${OBJECTDIR}/_ext/1266796427" 
	@${RM} ${OBJECTDIR}/_ext/1266796427/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1266796427/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/Mieko/Downloads/Car_Project/adc.c  -o ${OBJECTDIR}/_ext/1266796427/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1266796427/adc.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1266796427/utils.o: C:/Users/Mieko/Downloads/Car_Project/utils.c  .generated_files/flags/default/2bf385aa686fc8ee691c8c03a7bd979943ae6f54 .generated_files/flags/default/74b34707da22605293d6311696ae0a4a34fb9101
	@${MKDIR} "${OBJECTDIR}/_ext/1266796427" 
	@${RM} ${OBJECTDIR}/_ext/1266796427/utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1266796427/utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Users/Mieko/Downloads/Car_Project/utils.c  -o ${OBJECTDIR}/_ext/1266796427/utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1266796427/utils.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/LTC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/LTC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST)  
	
else
${DISTDIR}/LTC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/LTC.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST)  
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/LTC.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
