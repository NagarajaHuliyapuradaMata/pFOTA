

#if !defined (PDUR_LCFG_H)
# define PDUR_LCFG_H

# include "Types_SwcServicePduR.hpp"
# include "PbCfgSwcServicePduR.hpp"

#include "SwcServiceCanTp.hpp"
#include "SwcApplDcm.hpp"
#include "EcuabCanIf.hpp"
#include "CddApplCom.hpp"

#define PDUR_BMTXBUFFERARRAYRAM                                                                     STD_OFF
#define PDUR_BMTXBUFFERINDROM                                                                       STD_OFF
#define PDUR_BMTXBUFFERROMIDXOFBMTXBUFFERINDROM                                                     STD_OFF
#define PDUR_BMTXBUFFERINSTANCERAM                                                                  STD_OFF
#define PDUR_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM                                       STD_OFF
#define PDUR_BMTXBUFFERARRAYRAMWRITEIDXOFBMTXBUFFERINSTANCERAM                                      STD_OFF
#define PDUR_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM                                                 STD_OFF
#define PDUR_TXBUFFERUSEDOFBMTXBUFFERINSTANCERAM                                                    STD_OFF
#define PDUR_BMTXBUFFERINSTANCEROM                                                                  STD_OFF
#define PDUR_BMTXBUFFERROMIDXOFBMTXBUFFERINSTANCEROM                                                STD_OFF
#define PDUR_BMTXBUFFERRAM                                                                          STD_OFF
#define PDUR_ALLOCATEDOFBMTXBUFFERRAM                                                               STD_OFF
#define PDUR_BMTXBUFFERARRAYRAMINSTANCESTOPIDXOFBMTXBUFFERRAM                                       STD_OFF
#define PDUR_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERRAM                                               STD_OFF
#define PDUR_BMTXBUFFERARRAYRAMWRITEIDXOFBMTXBUFFERRAM                                              STD_OFF
#define PDUR_PDURBUFFERSTATEOFBMTXBUFFERRAM                                                         STD_OFF
#define PDUR_RXLENGTHOFBMTXBUFFERRAM                                                                STD_OFF
#define PDUR_BMTXBUFFERROM                                                                          STD_OFF
#define PDUR_BMTXBUFFERARRAYRAMENDIDXOFBMTXBUFFERROM                                                STD_OFF
#define PDUR_BMTXBUFFERARRAYRAMLENGTHOFBMTXBUFFERROM                                                STD_OFF
#define PDUR_BMTXBUFFERARRAYRAMSTARTIDXOFBMTXBUFFERROM                                              STD_OFF
#define PDUR_BMTXBUFFERINSTANCEROMENDIDXOFBMTXBUFFERROM                                             STD_OFF
#define PDUR_BMTXBUFFERINSTANCEROMSTARTIDXOFBMTXBUFFERROM                                           STD_OFF
#define PDUR_CONFIGID                                                                               STD_ON
#define PDUR_COREID2COREMANAGERROM                                                                  STD_OFF
#define PDUR_COREMANAGERROMIDXOFCOREID2COREMANAGERROM                                               STD_OFF
#define PDUR_COREMANAGERROMUSEDOFCOREID2COREMANAGERROM                                              STD_OFF
#define PDUR_INVALIDHNDOFCOREID2COREMANAGERROM                                                      STD_OFF
#define PDUR_COREMANAGERROM                                                                         STD_ON
#define PDUR_MMROMINDENDIDXOFCOREMANAGERROM                                                         STD_ON
#define PDUR_MMROMINDSTARTIDXOFCOREMANAGERROM                                                       STD_ON
#define PDUR_MMROMINDUSEDOFCOREMANAGERROM                                                           STD_ON
#define PDUR_SRCCOREROMENDIDXOFCOREMANAGERROM                                                       STD_OFF
#define PDUR_SRCCOREROMSTARTIDXOFCOREMANAGERROM                                                     STD_OFF
#define PDUR_DEFERREDEVENTCACHEARRAYRAM                                                             STD_OFF
#define PDUR_RMGDESTROMIDXOFDEFERREDEVENTCACHEARRAYRAM                                              STD_OFF
#define PDUR_DEFERREDEVENTCACHERAM                                                                  STD_OFF
#define PDUR_DEFERREDEVENTCACHEARRAYRAMREADIDXOFDEFERREDEVENTCACHERAM                               STD_OFF
#define PDUR_DEFERREDEVENTCACHEARRAYRAMWRITEIDXOFDEFERREDEVENTCACHERAM                              STD_OFF
#define PDUR_DEFERREDEVENTCACHEROM                                                                  STD_OFF
#define PDUR_DEFERREDEVENTCACHEARRAYRAMENDIDXOFDEFERREDEVENTCACHEROM                                STD_OFF
#define PDUR_DEFERREDEVENTCACHEARRAYRAMLENGTHOFDEFERREDEVENTCACHEROM                                STD_OFF
#define PDUR_DEFERREDEVENTCACHEARRAYRAMSTARTIDXOFDEFERREDEVENTCACHEROM                              STD_OFF
#define PDUR_EXCLUSIVEAREAROM                                                                       STD_ON
#define PDUR_LOCKOFEXCLUSIVEAREAROM                                                                 STD_ON
#define PDUR_UNLOCKOFEXCLUSIVEAREAROM                                                               STD_ON
#define PDUR_FINALMAGICNUMBER                                                                       STD_OFF
#define PDUR_FMFIFOELEMENTRAM                                                                       STD_OFF
#define PDUR_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM                                                     STD_OFF
#define PDUR_DEDICATEDTXBUFFEROFFMFIFOELEMENTRAM                                                    STD_OFF
#define PDUR_RMDESTROMIDXOFFMFIFOELEMENTRAM                                                         STD_OFF
#define PDUR_STATEOFFMFIFOELEMENTRAM                                                                STD_OFF
#define PDUR_FMFIFOINSTANCERAM                                                                      STD_OFF
#define PDUR_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM                                            STD_OFF
#define PDUR_FMFIFOINSTANCEROM                                                                      STD_OFF
#define PDUR_FMFIFOROMIDXOFFMFIFOINSTANCEROM                                                        STD_OFF
#define PDUR_FMFIFORAM                                                                              STD_OFF
#define PDUR_FILLLEVELOFFMFIFORAM                                                                   STD_OFF
#define PDUR_FMFIFOELEMENTRAMREADIDXOFFMFIFORAM                                                     STD_OFF
#define PDUR_FMFIFOELEMENTRAMWRITEIDXOFFMFIFORAM                                                    STD_OFF
#define PDUR_PENDINGCONFIRMATIONSOFFMFIFORAM                                                        STD_OFF
#define PDUR_TPTXSMSTATEOFFMFIFORAM                                                                 STD_OFF
#define PDUR_FMFIFOROM                                                                              STD_OFF
#define PDUR_BMTXBUFFERINDROMENDIDXOFFMFIFOROM                                                      STD_OFF
#define PDUR_BMTXBUFFERINDROMLENGTHOFFMFIFOROM                                                      STD_OFF
#define PDUR_BMTXBUFFERINDROMSTARTIDXOFFMFIFOROM                                                    STD_OFF
#define PDUR_FMFIFOELEMENTRAMENDIDXOFFMFIFOROM                                                      STD_OFF
#define PDUR_FMFIFOELEMENTRAMLENGTHOFFMFIFOROM                                                      STD_OFF
#define PDUR_FMFIFOELEMENTRAMSTARTIDXOFFMFIFOROM                                                    STD_OFF
#define PDUR_LOCKROMIDXOFFMFIFOROM                                                                  STD_OFF
#define PDUR_LOCKROMUSEDOFFMFIFOROM                                                                 STD_OFF
#define PDUR_FM_ACTIVATENEXT_FMSMSTATEHANDLER                                                       STD_OFF
#define PDUR_FCTPTROFFM_ACTIVATENEXT_FMSMSTATEHANDLER                                               STD_OFF
#define PDUR_FM_ACTIVATEREAD_FMSMSTATEHANDLER                                                       STD_OFF
#define PDUR_FCTPTROFFM_ACTIVATEREAD_FMSMSTATEHANDLER                                               STD_OFF
#define PDUR_FM_ACTIVATEWRITE_FMSMSTATEHANDLER                                                      STD_OFF
#define PDUR_FCTPTROFFM_ACTIVATEWRITE_FMSMSTATEHANDLER                                              STD_OFF
#define PDUR_FM_FINISHREAD_FMSMSTATEHANDLER                                                         STD_OFF
#define PDUR_FCTPTROFFM_FINISHREAD_FMSMSTATEHANDLER                                                 STD_OFF
#define PDUR_FM_FINISHWRITE_FMSMSTATEHANDLER                                                        STD_OFF
#define PDUR_FCTPTROFFM_FINISHWRITE_FMSMSTATEHANDLER                                                STD_OFF
#define PDUR_FM_TPDISABLEROUTING_FMSMSTATEHANDLER                                                   STD_OFF
#define PDUR_FCTPTROFFM_TPDISABLEROUTING_FMSMSTATEHANDLER                                           STD_OFF
#define PDUR_GENERALPROPERTIESROM                                                                   STD_OFF
#define PDUR_HASIFTXFIFOOFGENERALPROPERTIESROM                                                      STD_OFF
#define PDUR_HASTPTXBUFFEREDFORWARDINGOFGENERALPROPERTIESROM                                        STD_OFF
#define PDUR_INITDATAHASHCODE                                                                       STD_OFF
#define PDUR_INITIALIZED                                                                            STD_ON
#define PDUR_INTERFACEFIFOQUEUEARRAYRAM                                                             STD_OFF
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAM                                                           STD_OFF
#define PDUR_ACTUALLENGTHOFINTERFACEFIFOQUEUEELEMENTRAM                                             STD_OFF
#define PDUR_INTERFACEFIFOQUEUERAM                                                                  STD_OFF
#define PDUR_FIFOFULLOFINTERFACEFIFOQUEUERAM                                                        STD_OFF
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAMREADIDXOFINTERFACEFIFOQUEUERAM                             STD_OFF
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAMWRITEIDXOFINTERFACEFIFOQUEUERAM                            STD_OFF
#define PDUR_INTERFACEFIFOQUEUEROM                                                                  STD_OFF
#define PDUR_INTERFACEFIFOQUEUEARRAYRAMENDIDXOFINTERFACEFIFOQUEUEROM                                STD_OFF
#define PDUR_INTERFACEFIFOQUEUEARRAYRAMSTARTIDXOFINTERFACEFIFOQUEUEROM                              STD_OFF
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAMENDIDXOFINTERFACEFIFOQUEUEROM                              STD_OFF
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAMSTARTIDXOFINTERFACEFIFOQUEUEROM                            STD_OFF
#define PDUR_MAXPDULENGTHOFINTERFACEFIFOQUEUEROM                                                    STD_OFF
#define PDUR_RMDESTROMIDXOFINTERFACEFIFOQUEUEROM                                                    STD_OFF
#define PDUR_LOCKROM                                                                                STD_ON
#define PDUR_EXCLUSIVEAREAROMIDXOFLOCKROM                                                           STD_ON
#define PDUR_EXCLUSIVEAREAROMUSEDOFLOCKROM                                                          STD_ON
#define PDUR_SPINLOCKRAMIDXOFLOCKROM                                                                STD_OFF
#define PDUR_SPINLOCKRAMUSEDOFLOCKROM                                                               STD_OFF
#define PDUR_MCQBUFFERARRAYRAM                                                                      STD_OFF
#define PDUR_MCQBUFFERRAM                                                                           STD_OFF
#define PDUR_MCQBUFFERARRAYRAMPENDINGREADIDXOFMCQBUFFERRAM                                          STD_OFF
#define PDUR_MCQBUFFERARRAYRAMPENDINGWRITEIDXOFMCQBUFFERRAM                                         STD_OFF
#define PDUR_MCQBUFFERARRAYRAMREADIDXOFMCQBUFFERRAM                                                 STD_OFF
#define PDUR_MCQBUFFERARRAYRAMWRITEIDXOFMCQBUFFERRAM                                                STD_OFF
#define PDUR_MCQBUFFERROM                                                                           STD_OFF
#define PDUR_MCQBUFFERARRAYRAMENDIDXOFMCQBUFFERROM                                                  STD_OFF
#define PDUR_MCQBUFFERARRAYRAMLENGTHOFMCQBUFFERROM                                                  STD_OFF
#define PDUR_MCQBUFFERARRAYRAMSTARTIDXOFMCQBUFFERROM                                                STD_OFF
#define PDUR_MMROM                                                                                  STD_ON
#define PDUR_CANCELRECEIVESUPPORTEDOFMMROM                                                          STD_OFF
#define PDUR_CHANGEPARAMETERSUPPORTEDOFMMROM                                                        STD_OFF
#define PDUR_COREMANAGERROMIDXOFMMROM                                                               STD_ON
#define PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM                                                       STD_OFF
#define PDUR_LOIFCANCELTRANSMITFCTPTROFMMROM                                                        STD_OFF
#define PDUR_LOIFOFMMROM                                                                            STD_ON
#define PDUR_LOIFTRANSMITFCTPTROFMMROM                                                              STD_ON
#define PDUR_LOTPCANCELRECEIVEFCTPTROFMMROM                                                         STD_OFF
#define PDUR_LOTPCANCELTRANSMITFCTPTROFMMROM                                                        STD_OFF
#define PDUR_LOTPCHANGEPARAMETERFCTPTROFMMROM                                                       STD_OFF
#define PDUR_LOTPOFMMROM                                                                            STD_ON
#define PDUR_LOTPTRANSMITFCTPTROFMMROM                                                              STD_ON
#define PDUR_MASKEDBITSOFMMROM                                                                      STD_ON
#define PDUR_RMGDESTROMENDIDXOFMMROM                                                                STD_ON
#define PDUR_RMGDESTROMSTARTIDXOFMMROM                                                              STD_ON
#define PDUR_RMGDESTROMUSEDOFMMROM                                                                  STD_ON
#define PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM                                                       STD_OFF
#define PDUR_UPIFOFMMROM                                                                            STD_ON
#define PDUR_UPIFRXINDICATIONFCTPTROFMMROM                                                          STD_ON
#define PDUR_UPIFTRIGGERTRANSMITFCTPTROFMMROM                                                       STD_OFF
#define PDUR_UPIFTXCONFIRMATIONFCTPTROFMMROM                                                        STD_ON
#define PDUR_UPTPCOPYRXDATAFCTPTROFMMROM                                                            STD_ON
#define PDUR_UPTPCOPYTXDATAFCTPTROFMMROM                                                            STD_ON
#define PDUR_UPTPOFMMROM                                                                            STD_ON
#define PDUR_UPTPSTARTOFRECEPTIONFCTPTROFMMROM                                                      STD_ON
#define PDUR_UPTPTPRXINDICATIONFCTPTROFMMROM                                                        STD_ON
#define PDUR_UPTPTPTXCONFIRMATIONFCTPTROFMMROM                                                      STD_ON
#define PDUR_MMROMIND                                                                               STD_ON
#define PDUR_QUEUEFCTPTRROM                                                                         STD_OFF
#define PDUR_FLUSHFCTPTROFQUEUEFCTPTRROM                                                            STD_OFF
#define PDUR_GETFCTPTROFQUEUEFCTPTRROM                                                              STD_OFF
#define PDUR_GETFILLLEVELFCTPTROFQUEUEFCTPTRROM                                                     STD_OFF
#define PDUR_PUTFCTPTROFQUEUEFCTPTRROM                                                              STD_OFF
#define PDUR_REMOVEFCTPTROFQUEUEFCTPTRROM                                                           STD_OFF
#define PDUR_RMBUFFEREDIFPROPERTIESRAM                                                              STD_OFF
#define PDUR_IFSMSTATEOFRMBUFFEREDIFPROPERTIESRAM                                                   STD_OFF
#define PDUR_RMBUFFEREDIFPROPERTIESROM                                                              STD_OFF
#define PDUR_DEDICATEDTXBUFFEROFRMBUFFEREDIFPROPERTIESROM                                           STD_OFF
#define PDUR_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                                          STD_OFF
#define PDUR_INTERFACEFIFOQUEUEROMIDXOFRMBUFFEREDIFPROPERTIESROM                                    STD_OFF
#define PDUR_INTERFACEFIFOQUEUEROMUSEDOFRMBUFFEREDIFPROPERTIESROM                                   STD_OFF
#define PDUR_MAXPDULENGTHOFRMBUFFEREDIFPROPERTIESROM                                                STD_OFF
#define PDUR_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM                                      STD_OFF
#define PDUR_QUEUEFCTPTRROMIDXOFRMBUFFEREDIFPROPERTIESROM                                           STD_OFF
#define PDUR_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                                                   STD_OFF
#define PDUR_SINGLEBUFFERROMIDXOFRMBUFFEREDIFPROPERTIESROM                                          STD_OFF
#define PDUR_SINGLEBUFFERROMUSEDOFRMBUFFEREDIFPROPERTIESROM                                         STD_OFF
#define PDUR_RMBUFFEREDTPPROPERTIESRAM                                                              STD_OFF
#define PDUR_FMFIFOELEMENTRAMIDXOFRMBUFFEREDTPPROPERTIESRAM                                         STD_OFF
#define PDUR_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM                                                 STD_OFF
#define PDUR_RMBUFFEREDTPPROPERTIESROM                                                              STD_OFF
#define PDUR_DEDICATEDTXBUFFEROFRMBUFFEREDTPPROPERTIESROM                                           STD_OFF
#define PDUR_FMFIFOROMIDXOFRMBUFFEREDTPPROPERTIESROM                                                STD_OFF
#define PDUR_METADATALENGTHOFRMBUFFEREDTPPROPERTIESROM                                              STD_OFF
#define PDUR_METADATALENGTHUSEDOFRMBUFFEREDTPPROPERTIESROM                                          STD_OFF
#define PDUR_QUEUEDDESTCNTOFRMBUFFEREDTPPROPERTIESROM                                               STD_OFF
#define PDUR_TPTHRESHOLDOFRMBUFFEREDTPPROPERTIESROM                                                 STD_OFF
#define PDUR_RMDESTROM                                                                              STD_ON
#define PDUR_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                                   STD_OFF
#define PDUR_RMDESTRPGROMIDXOFRMDESTROM                                                             STD_OFF
#define PDUR_RMDESTRPGROMUSEDOFRMDESTROM                                                            STD_OFF
#define PDUR_RMGDESTROMIDXOFRMDESTROM                                                               STD_ON
#define PDUR_RMSRCROMIDXOFRMDESTROM                                                                 STD_ON
#define PDUR_ROUTINGTYPEOFRMDESTROM                                                                 STD_ON
#define PDUR_RMDESTRPGRAM                                                                           STD_OFF
#define PDUR_ENABLEDCNTOFRMDESTRPGRAM                                                               STD_OFF
#define PDUR_RMDESTRPGROM                                                                           STD_OFF
#define PDUR_INITIALENABLEDCNTOFRMDESTRPGROM                                                        STD_OFF
#define PDUR_RMDESTROMIDXOFRMDESTRPGROM                                                             STD_OFF
#define PDUR_RMDESTROMUSEDOFRMDESTRPGROM                                                            STD_OFF
#define PDUR_RMDESTRPGROMIND                                                                        STD_OFF
#define PDUR_RMGDESTNTO1INFORAM                                                                     STD_OFF
#define PDUR_RMDESTROMIDXOFRMGDESTNTO1INFORAM                                                       STD_OFF
#define PDUR_TRANSMISSIONACTIVEOFRMGDESTNTO1INFORAM                                                 STD_OFF
#define PDUR_RMGDESTROM                                                                             STD_ON
#define PDUR_DESTHNDOFRMGDESTROM                                                                    STD_ON
#define PDUR_DIRECTIONOFRMGDESTROM                                                                  STD_ON
#define PDUR_FMFIFOINSTANCEROMIDXOFRMGDESTROM                                                       STD_OFF
#define PDUR_FMFIFOINSTANCEROMUSEDOFRMGDESTROM                                                      STD_OFF
#define PDUR_LOCKROMIDXOFRMGDESTROM                                                                 STD_ON
#define PDUR_MMROMIDXOFRMGDESTROM                                                                   STD_ON
#define PDUR_PDURDESTPDUPROCESSINGOFRMGDESTROM                                                      STD_ON
#define PDUR_RMBUFFEREDIFPROPERTIESROMIDXOFRMGDESTROM                                               STD_OFF
#define PDUR_RMBUFFEREDIFPROPERTIESROMUSEDOFRMGDESTROM                                              STD_OFF
#define PDUR_RMDESTROMIDXOFRMGDESTROM                                                               STD_ON
#define PDUR_RMDESTROMUSEDOFRMGDESTROM                                                              STD_ON
#define PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM                                                      STD_OFF
#define PDUR_RMGDESTNTO1INFORAMUSEDOFRMGDESTROM                                                     STD_OFF
#define PDUR_RMGDESTTPTXSTATERAMIDXOFRMGDESTROM                                                     STD_OFF
#define PDUR_RMGDESTTPTXSTATERAMUSEDOFRMGDESTROM                                                    STD_OFF
#define PDUR_SMGDESTROMIDXOFRMGDESTROM                                                              STD_OFF
#define PDUR_SMGDESTROMUSEDOFRMGDESTROM                                                             STD_OFF
#define PDUR_RMGDESTTPTXSTATERAM                                                                    STD_OFF
#define PDUR_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM                                                   STD_OFF
#define PDUR_RMIF_TXCONFIRMATION_STATEHANDLER                                                       STD_OFF
#define PDUR_FCTPTROFRMIF_TXCONFIRMATION_STATEHANDLER                                               STD_OFF
#define PDUR_RMSRCROM                                                                               STD_ON
#define PDUR_LOCKROMIDXOFRMSRCROM                                                                   STD_ON
#define PDUR_MMROMIDXOFRMSRCROM                                                                     STD_ON
#define PDUR_RMBUFFEREDTPPROPERTIESROMIDXOFRMSRCROM                                                 STD_OFF
#define PDUR_RMBUFFEREDTPPROPERTIESROMUSEDOFRMSRCROM                                                STD_OFF
#define PDUR_RMDESTROMENDIDXOFRMSRCROM                                                              STD_ON
#define PDUR_RMDESTROMLENGTHOFRMSRCROM                                                              STD_ON
#define PDUR_RMDESTROMSTARTIDXOFRMSRCROM                                                            STD_ON
#define PDUR_SMSRCROMIDXOFRMSRCROM                                                                  STD_OFF
#define PDUR_SMSRCROMUSEDOFRMSRCROM                                                                 STD_OFF
#define PDUR_SRCHNDOFRMSRCROM                                                                       STD_ON
#define PDUR_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM                                                     STD_OFF
#define PDUR_TXCONFIRMATIONSUPPORTEDOFRMSRCROM                                                      STD_ON
#define PDUR_RMTP_CANCELRECEIVE_TPRXSMSTATEHANDLER                                                  STD_OFF
#define PDUR_FCTPTROFRMTP_CANCELRECEIVE_TPRXSMSTATEHANDLER                                          STD_OFF
#define PDUR_RMTP_CHECKREADY2TRANSMIT_TPTXSMSTATEHANDLER                                            STD_OFF
#define PDUR_FCTPTROFRMTP_CHECKREADY2TRANSMIT_TPTXSMSTATEHANDLER                                    STD_OFF
#define PDUR_RMTP_COPYRXDATA_TPRXSMSTATEHANDLER                                                     STD_OFF
#define PDUR_FCTPTROFRMTP_COPYRXDATA_TPRXSMSTATEHANDLER                                             STD_OFF
#define PDUR_RMTP_FINISHRECEPTION_TPTXSMSTATEHANDLER                                                STD_OFF
#define PDUR_FCTPTROFRMTP_FINISHRECEPTION_TPTXSMSTATEHANDLER                                        STD_OFF
#define PDUR_RMTP_FINISHTRANSMISSION_TPTXSMSTATEHANDLER                                             STD_OFF
#define PDUR_FCTPTROFRMTP_FINISHTRANSMISSION_TPTXSMSTATEHANDLER                                     STD_OFF
#define PDUR_RMTP_STARTOFRECEPTION_TPRXSMSTATEHANDLER                                               STD_OFF
#define PDUR_FCTPTROFRMTP_STARTOFRECEPTION_TPRXSMSTATEHANDLER                                       STD_OFF
#define PDUR_RMTP_TPRXINDICATION_TPRXSMSTATEHANDLER                                                 STD_OFF
#define PDUR_FCTPTROFRMTP_TPRXINDICATION_TPRXSMSTATEHANDLER                                         STD_OFF
#define PDUR_RMTRANSMITFCTPTR                                                                       STD_ON
#define PDUR_RMTXINSTSMROM                                                                          STD_OFF
#define PDUR_PDUR_RMTP_TXINST_CANCELTRANSMITOFRMTXINSTSMROM                                         STD_OFF
#define PDUR_PDUR_RMTP_TXINST_COPYTXDATAOFRMTXINSTSMROM                                             STD_OFF
#define PDUR_PDUR_RMTP_TXINST_TRIGGERTRANSMITOFRMTXINSTSMROM                                        STD_OFF
#define PDUR_PDUR_RMTP_TXINST_TXCONFIRMATIONOFRMTXINSTSMROM                                         STD_OFF
#define PDUR_RPGRAM                                                                                 STD_OFF
#define PDUR_ENABLEDOFRPGRAM                                                                        STD_OFF
#define PDUR_RPGROM                                                                                 STD_OFF
#define PDUR_ENABLEDATINITOFRPGROM                                                                  STD_OFF
#define PDUR_INVALIDHNDOFRPGROM                                                                     STD_OFF
#define PDUR_RMDESTRPGROMINDENDIDXOFRPGROM                                                          STD_OFF
#define PDUR_RMDESTRPGROMINDSTARTIDXOFRPGROM                                                        STD_OFF
#define PDUR_RMDESTRPGROMINDUSEDOFRPGROM                                                            STD_OFF
#define PDUR_RXIF2DEST                                                                              STD_OFF
#define PDUR_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST                                                STD_OFF
#define PDUR_INVALIDHNDOFRXIF2DEST                                                                  STD_OFF
#define PDUR_RMSRCROMIDXOFRXIF2DEST                                                                 STD_OFF
#define PDUR_RXTP2DEST                                                                              STD_ON
#define PDUR_BSWMPDURTPRXINDICATIONCALLBACKOFRXTP2DEST                                              STD_OFF
#define PDUR_BSWMPDURTPSTARTOFRECEPTIONCALLBACKOFRXTP2DEST                                          STD_OFF
#define PDUR_INVALIDHNDOFRXTP2DEST                                                                  STD_OFF
#define PDUR_RMSRCROMIDXOFRXTP2DEST                                                                 STD_ON
#define PDUR_RMSRCROMUSEDOFRXTP2DEST                                                                STD_ON
#define PDUR_RXTP2SRC                                                                               STD_OFF
#define PDUR_INVALIDHNDOFRXTP2SRC                                                                   STD_OFF
#define PDUR_RMDESTROMIDXOFRXTP2SRC                                                                 STD_OFF
#define PDUR_SINGLEBUFFERARRAYRAM                                                                   STD_OFF
#define PDUR_SINGLEBUFFERINITVALUESROM                                                              STD_OFF
#define PDUR_SINGLEBUFFERRAM                                                                        STD_OFF
#define PDUR_ACTUALLENGTHOFSINGLEBUFFERRAM                                                          STD_OFF
#define PDUR_SINGLEBUFFERROM                                                                        STD_OFF
#define PDUR_RMDESTROMIDXOFSINGLEBUFFERROM                                                          STD_OFF
#define PDUR_SINGLEBUFFERARRAYRAMENDIDXOFSINGLEBUFFERROM                                            STD_OFF
#define PDUR_SINGLEBUFFERARRAYRAMLENGTHOFSINGLEBUFFERROM                                            STD_OFF
#define PDUR_SINGLEBUFFERARRAYRAMSTARTIDXOFSINGLEBUFFERROM                                          STD_OFF
#define PDUR_SINGLEBUFFERINITVALUESROMENDIDXOFSINGLEBUFFERROM                                       STD_OFF
#define PDUR_SINGLEBUFFERINITVALUESROMLENGTHOFSINGLEBUFFERROM                                       STD_OFF
#define PDUR_SINGLEBUFFERINITVALUESROMSTARTIDXOFSINGLEBUFFERROM                                     STD_OFF
#define PDUR_SIZEOFCOREMANAGERROM                                                                   STD_ON
#define PDUR_SIZEOFEXCLUSIVEAREAROM                                                                 STD_ON
#define PDUR_SIZEOFLOCKROM                                                                          STD_ON
#define PDUR_SIZEOFMMROM                                                                            STD_ON
#define PDUR_SIZEOFMMROMIND                                                                         STD_ON
#define PDUR_SIZEOFRMDESTROM                                                                        STD_ON
#define PDUR_SIZEOFRMGDESTROM                                                                       STD_ON
#define PDUR_SIZEOFRMSRCROM                                                                         STD_ON
#define PDUR_SIZEOFRMTRANSMITFCTPTR                                                                 STD_ON
#define PDUR_SIZEOFRXTP2DEST                                                                        STD_ON
#define PDUR_SIZEOFTX2LO                                                                            STD_ON
#define PDUR_SIZEOFTXIF2UP                                                                          STD_ON
#define PDUR_SIZEOFTXTP2SRC                                                                         STD_ON
#define PDUR_SMDATAPLANEROM                                                                         STD_OFF
#define PDUR_SMFIBRAMENDIDXOFSMDATAPLANEROM                                                         STD_OFF
#define PDUR_SMFIBRAMSTARTIDXOFSMDATAPLANEROM                                                       STD_OFF
#define PDUR_SMFIBRAMUSEDOFSMDATAPLANEROM                                                           STD_OFF
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM                                STD_OFF
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM                               STD_OFF
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM                            STD_OFF
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM                           STD_OFF
#define PDUR_SMFIBRAM                                                                               STD_OFF
#define PDUR_LEARNEDCONNECTIONIDOFSMFIBRAM                                                          STD_OFF
#define PDUR_SMGDESTFILTERFCTPTR                                                                    STD_OFF
#define PDUR_SMGDESTROM                                                                             STD_OFF
#define PDUR_CONNECTIONIDOFSMGDESTROM                                                               STD_OFF
#define PDUR_METADATALENGTHOFSMGDESTROM                                                             STD_OFF
#define PDUR_SMDATAPLANEROMIDXOFSMGDESTROM                                                          STD_OFF
#define PDUR_SMGDESTFILTERFCTPTRIDXOFSMGDESTROM                                                     STD_OFF
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTR                                           STD_OFF
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROM                                                   STD_OFF
#define PDUR_MASKOFSMLINEARTATOSACALCULATIONSTRATEGYROM                                             STD_OFF
#define PDUR_OFFSETOFSMLINEARTATOSACALCULATIONSTRATEGYROM                                           STD_OFF
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROM                                               STD_OFF
#define PDUR_SAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                       STD_OFF
#define PDUR_SASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                   STD_OFF
#define PDUR_TAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                       STD_OFF
#define PDUR_TASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                   STD_OFF
#define PDUR_SMSRCFILTERFCTPTR                                                                      STD_OFF
#define PDUR_SMSRCROM                                                                               STD_OFF
#define PDUR_CONNECTIONIDOFSMSRCROM                                                                 STD_OFF
#define PDUR_METADATALENGTHOFSMSRCROM                                                               STD_OFF
#define PDUR_SMDATAPLANEROMIDXOFSMSRCROM                                                            STD_OFF
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRIDXOFSMSRCROM                              STD_OFF
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRUSEDOFSMSRCROM                             STD_OFF
#define PDUR_SMSRCFILTERFCTPTRIDXOFSMSRCROM                                                         STD_OFF
#define PDUR_SPINLOCKRAM                                                                            STD_OFF
#define PDUR_COUNTEROFSPINLOCKRAM                                                                   STD_OFF
#define PDUR_LOCKVARIABLEOFSPINLOCKRAM                                                              STD_OFF
#define PDUR_SRCCOREROM                                                                             STD_OFF
#define PDUR_DEFERREDEVENTCACHEROMIDXOFSRCCOREROM                                                   STD_OFF
#define PDUR_DEFERREDEVENTCACHEROMUSEDOFSRCCOREROM                                                  STD_OFF
#define PDUR_MCQBUFFERROMIDXOFSRCCOREROM                                                            STD_OFF
#define PDUR_MCQBUFFERROMUSEDOFSRCCOREROM                                                           STD_OFF
#define PDUR_TX2LO                                                                                  STD_ON
#define PDUR_BSWMPDURTRANSMITCALLBACKOFTX2LO                                                        STD_OFF
#define PDUR_CANCELTRANSMITUSEDOFTX2LO                                                              STD_OFF
#define PDUR_INVALIDHNDOFTX2LO                                                                      STD_OFF
#define PDUR_RMSRCROMIDXOFTX2LO                                                                     STD_ON
#define PDUR_RMSRCROMUSEDOFTX2LO                                                                    STD_ON
#define PDUR_RMTRANSMITFCTPTRIDXOFTX2LO                                                             STD_ON
#define PDUR_TXIF2UP                                                                                STD_ON
#define PDUR_BSWMPDURTXCONFIRMATIONCALLBACKOFTXIF2UP                                                STD_OFF
#define PDUR_INVALIDHNDOFTXIF2UP                                                                    STD_OFF
#define PDUR_RMGDESTROMIDXOFTXIF2UP                                                                 STD_ON
#define PDUR_TXCONFIRMATIONUSEDOFTXIF2UP                                                            STD_ON
#define PDUR_TXTP2SRC                                                                               STD_ON
#define PDUR_BSWMPDURTPTXCONFIRMATIONCALLBACKOFTXTP2SRC                                             STD_OFF
#define PDUR_INVALIDHNDOFTXTP2SRC                                                                   STD_OFF
#define PDUR_RMGDESTROMIDXOFTXTP2SRC                                                                STD_ON
#define PDUR_PCCONFIG                                                                               STD_ON
#define PDUR_CONFIGIDOFPCCONFIG                                                                     STD_ON
#define PDUR_COREMANAGERROMOFPCCONFIG                                                               STD_ON
#define PDUR_EXCLUSIVEAREAROMOFPCCONFIG                                                             STD_ON
#define PDUR_FINALMAGICNUMBEROFPCCONFIG                                                             STD_OFF
#define PDUR_INITDATAHASHCODEOFPCCONFIG                                                             STD_OFF
#define PDUR_INITIALIZEDOFPCCONFIG                                                                  STD_ON
#define PDUR_LOCKROMOFPCCONFIG                                                                      STD_ON
#define PDUR_MMROMINDOFPCCONFIG                                                                     STD_ON
#define PDUR_MMROMOFPCCONFIG                                                                        STD_ON
#define PDUR_RMDESTROMOFPCCONFIG                                                                    STD_ON
#define PDUR_RMGDESTROMOFPCCONFIG                                                                   STD_ON
#define PDUR_RMSRCROMOFPCCONFIG                                                                     STD_ON
#define PDUR_RMTRANSMITFCTPTROFPCCONFIG                                                             STD_ON
#define PDUR_RXTP2DESTOFPCCONFIG                                                                    STD_ON
#define PDUR_SIZEOFCOREMANAGERROMOFPCCONFIG                                                         STD_ON
#define PDUR_SIZEOFEXCLUSIVEAREAROMOFPCCONFIG                                                       STD_ON
#define PDUR_SIZEOFLOCKROMOFPCCONFIG                                                                STD_ON
#define PDUR_SIZEOFMMROMINDOFPCCONFIG                                                               STD_ON
#define PDUR_SIZEOFMMROMOFPCCONFIG                                                                  STD_ON
#define PDUR_SIZEOFRMDESTROMOFPCCONFIG                                                              STD_ON
#define PDUR_SIZEOFRMGDESTROMOFPCCONFIG                                                             STD_ON
#define PDUR_SIZEOFRMSRCROMOFPCCONFIG                                                               STD_ON
#define PDUR_SIZEOFRMTRANSMITFCTPTROFPCCONFIG                                                       STD_ON
#define PDUR_SIZEOFRXTP2DESTOFPCCONFIG                                                              STD_ON
#define PDUR_SIZEOFTX2LOOFPCCONFIG                                                                  STD_ON
#define PDUR_SIZEOFTXIF2UPOFPCCONFIG                                                                STD_ON
#define PDUR_SIZEOFTXTP2SRCOFPCCONFIG                                                               STD_ON
#define PDUR_TX2LOOFPCCONFIG                                                                        STD_ON
#define PDUR_TXIF2UPOFPCCONFIG                                                                      STD_ON
#define PDUR_TXTP2SRCOFPCCONFIG                                                                     STD_ON

#define PDUR_NO_MMROMINDENDIDXOFCOREMANAGERROM                                                      255u
#define PDUR_NO_MMROMINDSTARTIDXOFCOREMANAGERROM                                                    255u
#define PDUR_NO_EXCLUSIVEAREAROMIDXOFLOCKROM                                                        255u
#define PDUR_NO_RMGDESTROMENDIDXOFMMROM                                                             255u
#define PDUR_NO_RMGDESTROMSTARTIDXOFMMROM                                                           255u
#define PDUR_NO_DESTHNDOFRMGDESTROM                                                                 255u
#define PDUR_NO_RMDESTROMIDXOFRMGDESTROM                                                            255u
#define PDUR_NO_SRCHNDOFRMSRCROM                                                                    255u
#define PDUR_NO_RMSRCROMIDXOFRXTP2DEST                                                              255u
#define PDUR_NO_RMSRCROMIDXOFTX2LO                                                                  255u

#define PDUR_EXISTS_SINGLE_BUFFER_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM               STD_OFF
#define PDUR_EXISTS_SIMPLE_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                 STD_OFF
#define PDUR_EXISTS_SHARED_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                 STD_OFF
#define PDUR_EXISTS_DIRECT_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM                        STD_OFF
#define PDUR_EXISTS_TRIGGER_TRANSMIT_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM              STD_OFF
#define PDUR_EXISTS_SINGLE_BUFFER_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                              STD_OFF
#define PDUR_EXISTS_FIFO_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                                       STD_OFF
#define PDUR_EXISTS_SHORTEN_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                    STD_OFF
#define PDUR_EXISTS_DISCARD_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                    STD_OFF
#define PDUR_EXISTS_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_OFF
#define PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_ON
#define PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM                                      STD_OFF
#define PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM                                              STD_OFF
#define PDUR_EXISTS_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_ON
#define PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_ON
#define PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM                                              STD_OFF
#define PDUR_EXISTS_RX_DIRECTIONOFRMGDESTROM                                                        STD_ON
#define PDUR_EXISTS_TX_DIRECTIONOFRMGDESTROM                                                        STD_ON
#define PDUR_EXISTS_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM                                      STD_OFF
#define PDUR_EXISTS_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM                                     STD_ON

#define PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x01u
#define PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x04u
#define PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x05u
#define PDUR_RX_DIRECTIONOFRMGDESTROM                                                               0x00u
#define PDUR_TX_DIRECTIONOFRMGDESTROM                                                               0x01u
#define PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM                                            0x01u

#define PDUR_LOIFOFMMROM_MASK                                                                       0x10u
#define PDUR_LOTPOFMMROM_MASK                                                                       0x08u
#define PDUR_RMGDESTROMUSEDOFMMROM_MASK                                                             0x04u
#define PDUR_UPIFOFMMROM_MASK                                                                       0x02u
#define PDUR_UPTPOFMMROM_MASK                                                                       0x01u

#define PDUR_ISDEF_MMROMINDENDIDXOFCOREMANAGERROM                                                   STD_OFF
#define PDUR_ISDEF_MMROMINDSTARTIDXOFCOREMANAGERROM                                                 STD_OFF
#define PDUR_ISDEF_MMROMINDUSEDOFCOREMANAGERROM                                                     STD_OFF
#define PDUR_ISDEF_LOCKOFEXCLUSIVEAREAROM                                                           STD_OFF
#define PDUR_ISDEF_UNLOCKOFEXCLUSIVEAREAROM                                                         STD_OFF
#define PDUR_ISDEF_EXCLUSIVEAREAROMIDXOFLOCKROM                                                     STD_OFF
#define PDUR_ISDEF_EXCLUSIVEAREAROMUSEDOFLOCKROM                                                    STD_OFF
#define PDUR_ISDEF_COREMANAGERROMIDXOFMMROM                                                         STD_OFF
#define PDUR_ISDEF_LOIFOFMMROM                                                                      STD_OFF
#define PDUR_ISDEF_LOIFTRANSMITFCTPTROFMMROM                                                        STD_OFF
#define PDUR_ISDEF_LOTPOFMMROM                                                                      STD_OFF
#define PDUR_ISDEF_LOTPTRANSMITFCTPTROFMMROM                                                        STD_OFF
#define PDUR_ISDEF_MASKEDBITSOFMMROM                                                                STD_OFF
#define PDUR_ISDEF_RMGDESTROMENDIDXOFMMROM                                                          STD_OFF
#define PDUR_ISDEF_RMGDESTROMSTARTIDXOFMMROM                                                        STD_OFF
#define PDUR_ISDEF_RMGDESTROMUSEDOFMMROM                                                            STD_OFF
#define PDUR_ISDEF_UPIFOFMMROM                                                                      STD_OFF
#define PDUR_ISDEF_UPIFRXINDICATIONFCTPTROFMMROM                                                    STD_OFF
#define PDUR_ISDEF_UPIFTXCONFIRMATIONFCTPTROFMMROM                                                  STD_OFF
#define PDUR_ISDEF_UPTPCOPYRXDATAFCTPTROFMMROM                                                      STD_OFF
#define PDUR_ISDEF_UPTPCOPYTXDATAFCTPTROFMMROM                                                      STD_OFF
#define PDUR_ISDEF_UPTPOFMMROM                                                                      STD_OFF
#define PDUR_ISDEF_UPTPSTARTOFRECEPTIONFCTPTROFMMROM                                                STD_OFF
#define PDUR_ISDEF_UPTPTPRXINDICATIONFCTPTROFMMROM                                                  STD_OFF
#define PDUR_ISDEF_UPTPTPTXCONFIRMATIONFCTPTROFMMROM                                                STD_OFF
#define PDUR_ISDEF_MMROMIND                                                                         STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFRMDESTROM                                                         STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFRMDESTROM                                                           STD_OFF
#define PDUR_ISDEF_ROUTINGTYPEOFRMDESTROM                                                           STD_OFF
#define PDUR_ISDEF_DESTHNDOFRMGDESTROM                                                              STD_OFF
#define PDUR_ISDEF_DIRECTIONOFRMGDESTROM                                                            STD_OFF
#define PDUR_ISDEF_LOCKROMIDXOFRMGDESTROM                                                           STD_OFF
#define PDUR_ISDEF_MMROMIDXOFRMGDESTROM                                                             STD_OFF
#define PDUR_ISDEF_PDURDESTPDUPROCESSINGOFRMGDESTROM                                                STD_OFF
#define PDUR_ISDEF_RMDESTROMIDXOFRMGDESTROM                                                         STD_OFF
#define PDUR_ISDEF_RMDESTROMUSEDOFRMGDESTROM                                                        STD_OFF
#define PDUR_ISDEF_LOCKROMIDXOFRMSRCROM                                                             STD_OFF
#define PDUR_ISDEF_MMROMIDXOFRMSRCROM                                                               STD_OFF
#define PDUR_ISDEF_RMDESTROMENDIDXOFRMSRCROM                                                        STD_OFF
#define PDUR_ISDEF_RMDESTROMLENGTHOFRMSRCROM                                                        STD_OFF
#define PDUR_ISDEF_RMDESTROMSTARTIDXOFRMSRCROM                                                      STD_OFF
#define PDUR_ISDEF_SRCHNDOFRMSRCROM                                                                 STD_OFF
#define PDUR_ISDEF_TXCONFIRMATIONSUPPORTEDOFRMSRCROM                                                STD_OFF
#define PDUR_ISDEF_RMTRANSMITFCTPTR                                                                 STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFRXTP2DEST                                                           STD_OFF
#define PDUR_ISDEF_RMSRCROMUSEDOFRXTP2DEST                                                          STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFTX2LO                                                               STD_OFF
#define PDUR_ISDEF_RMSRCROMUSEDOFTX2LO                                                              STD_OFF
#define PDUR_ISDEF_RMTRANSMITFCTPTRIDXOFTX2LO                                                       STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFTXIF2UP                                                           STD_OFF
#define PDUR_ISDEF_TXCONFIRMATIONUSEDOFTXIF2UP                                                      STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFTXTP2SRC                                                          STD_OFF
#define PDUR_ISDEF_COREMANAGERROMOFPCCONFIG                                                         STD_ON
#define PDUR_ISDEF_EXCLUSIVEAREAROMOFPCCONFIG                                                       STD_ON
#define PDUR_ISDEF_INITIALIZEDOFPCCONFIG                                                            STD_ON
#define PDUR_ISDEF_LOCKROMOFPCCONFIG                                                                STD_ON
#define PDUR_ISDEF_MMROMINDOFPCCONFIG                                                               STD_ON
#define PDUR_ISDEF_MMROMOFPCCONFIG                                                                  STD_ON
#define PDUR_ISDEF_RMDESTROMOFPCCONFIG                                                              STD_ON
#define PDUR_ISDEF_RMGDESTROMOFPCCONFIG                                                             STD_ON
#define PDUR_ISDEF_RMSRCROMOFPCCONFIG                                                               STD_ON
#define PDUR_ISDEF_RMTRANSMITFCTPTROFPCCONFIG                                                       STD_ON
#define PDUR_ISDEF_RXTP2DESTOFPCCONFIG                                                              STD_ON
#define PDUR_ISDEF_TX2LOOFPCCONFIG                                                                  STD_ON
#define PDUR_ISDEF_TXIF2UPOFPCCONFIG                                                                STD_ON
#define PDUR_ISDEF_TXTP2SRCOFPCCONFIG                                                               STD_ON

#define PDUR_EQ2_MMROMINDENDIDXOFCOREMANAGERROM
#define PDUR_EQ2_MMROMINDSTARTIDXOFCOREMANAGERROM
#define PDUR_EQ2_MMROMINDUSEDOFCOREMANAGERROM
#define PDUR_EQ2_LOCKOFEXCLUSIVEAREAROM
#define PDUR_EQ2_UNLOCKOFEXCLUSIVEAREAROM
#define PDUR_EQ2_EXCLUSIVEAREAROMIDXOFLOCKROM
#define PDUR_EQ2_EXCLUSIVEAREAROMUSEDOFLOCKROM
#define PDUR_EQ2_COREMANAGERROMIDXOFMMROM
#define PDUR_EQ2_LOIFOFMMROM
#define PDUR_EQ2_LOIFTRANSMITFCTPTROFMMROM
#define PDUR_EQ2_LOTPOFMMROM
#define PDUR_EQ2_LOTPTRANSMITFCTPTROFMMROM
#define PDUR_EQ2_MASKEDBITSOFMMROM
#define PDUR_EQ2_RMGDESTROMENDIDXOFMMROM
#define PDUR_EQ2_RMGDESTROMSTARTIDXOFMMROM
#define PDUR_EQ2_RMGDESTROMUSEDOFMMROM
#define PDUR_EQ2_UPIFOFMMROM
#define PDUR_EQ2_UPIFRXINDICATIONFCTPTROFMMROM
#define PDUR_EQ2_UPIFTXCONFIRMATIONFCTPTROFMMROM
#define PDUR_EQ2_UPTPCOPYRXDATAFCTPTROFMMROM
#define PDUR_EQ2_UPTPCOPYTXDATAFCTPTROFMMROM
#define PDUR_EQ2_UPTPOFMMROM
#define PDUR_EQ2_UPTPSTARTOFRECEPTIONFCTPTROFMMROM
#define PDUR_EQ2_UPTPTPRXINDICATIONFCTPTROFMMROM
#define PDUR_EQ2_UPTPTPTXCONFIRMATIONFCTPTROFMMROM
#define PDUR_EQ2_MMROMIND
#define PDUR_EQ2_RMGDESTROMIDXOFRMDESTROM
#define PDUR_EQ2_RMSRCROMIDXOFRMDESTROM
#define PDUR_EQ2_ROUTINGTYPEOFRMDESTROM
#define PDUR_EQ2_DESTHNDOFRMGDESTROM
#define PDUR_EQ2_DIRECTIONOFRMGDESTROM
#define PDUR_EQ2_LOCKROMIDXOFRMGDESTROM
#define PDUR_EQ2_MMROMIDXOFRMGDESTROM
#define PDUR_EQ2_PDURDESTPDUPROCESSINGOFRMGDESTROM
#define PDUR_EQ2_RMDESTROMIDXOFRMGDESTROM
#define PDUR_EQ2_RMDESTROMUSEDOFRMGDESTROM
#define PDUR_EQ2_LOCKROMIDXOFRMSRCROM
#define PDUR_EQ2_MMROMIDXOFRMSRCROM
#define PDUR_EQ2_RMDESTROMENDIDXOFRMSRCROM
#define PDUR_EQ2_RMDESTROMLENGTHOFRMSRCROM
#define PDUR_EQ2_RMDESTROMSTARTIDXOFRMSRCROM
#define PDUR_EQ2_SRCHNDOFRMSRCROM
#define PDUR_EQ2_TXCONFIRMATIONSUPPORTEDOFRMSRCROM
#define PDUR_EQ2_RMTRANSMITFCTPTR
#define PDUR_EQ2_RMSRCROMIDXOFRXTP2DEST
#define PDUR_EQ2_RMSRCROMUSEDOFRXTP2DEST
#define PDUR_EQ2_RMSRCROMIDXOFTX2LO
#define PDUR_EQ2_RMSRCROMUSEDOFTX2LO
#define PDUR_EQ2_RMTRANSMITFCTPTRIDXOFTX2LO
#define PDUR_EQ2_RMGDESTROMIDXOFTXIF2UP
#define PDUR_EQ2_TXCONFIRMATIONUSEDOFTXIF2UP
#define PDUR_EQ2_RMGDESTROMIDXOFTXTP2SRC
#define PDUR_EQ2_COREMANAGERROMOFPCCONFIG                                                           PduR_CoreManagerRom
#define PDUR_EQ2_EXCLUSIVEAREAROMOFPCCONFIG                                                         PduR_ExclusiveAreaRom
#define PDUR_EQ2_INITIALIZEDOFPCCONFIG                                                              (&(PduR_Initialized))
#define PDUR_EQ2_LOCKROMOFPCCONFIG                                                                  PduR_LockRom
#define PDUR_EQ2_MMROMINDOFPCCONFIG                                                                 PduR_MmRomInd
#define PDUR_EQ2_MMROMOFPCCONFIG                                                                    PduR_MmRom
#define PDUR_EQ2_RMDESTROMOFPCCONFIG                                                                PduR_RmDestRom
#define PDUR_EQ2_RMGDESTROMOFPCCONFIG                                                               PduR_RmGDestRom
#define PDUR_EQ2_RMSRCROMOFPCCONFIG                                                                 PduR_RmSrcRom
#define PDUR_EQ2_RMTRANSMITFCTPTROFPCCONFIG                                                         PduR_RmTransmitFctPtr
#define PDUR_EQ2_RXTP2DESTOFPCCONFIG                                                                PduR_RxTp2Dest
#define PDUR_EQ2_TX2LOOFPCCONFIG                                                                    PduR_Tx2Lo
#define PDUR_EQ2_TXIF2UPOFPCCONFIG                                                                  PduR_TxIf2Up
#define PDUR_EQ2_TXTP2SRCOFPCCONFIG                                                                 PduR_TxTp2Src

#define PduR_Config_Ptr                                                                             NULL_PTR

#define PduR_Config                                                                                 NULL_PTR

#define PDUR_CHECK_INIT_POINTER                                                                     STD_OFF
#define PDUR_FINAL_MAGIC_NUMBER                                                                     0x331Eu
#define PDUR_INDIVIDUAL_POSTBUILD                                                                   STD_OFF
#define PDUR_INIT_DATA                                                                              PDUR_CONST
#define PDUR_INIT_DATA_HASH_CODE                                                                    -863935689
#define PDUR_USE_ECUM_BSW_ERROR_HOOK                                                                STD_OFF
#define PDUR_USE_INIT_POINTER                                                                       STD_OFF

#define PDUR_LTCONFIG                                                                               STD_OFF

#define PDUR_MAX_TRIGGER_TRANSMIT_PDU_SIZE 1

#if(PDUR_FMFIFOELEMENTRAM == STD_OFF)
  #define PduR_FmFifoElementRamIterType uint16
#endif

#define PduR_GetConfigIdOfPCConfig()                                                                0u
#define PduR_GetCoreManagerRomOfPCConfig()                                                          PduR_CoreManagerRom
#define PduR_GetExclusiveAreaRomOfPCConfig()                                                        PduR_ExclusiveAreaRom
#define PduR_GetInitializedOfPCConfig()                                                             (&(PduR_Initialized))
#define PduR_GetLockRomOfPCConfig()                                                                 PduR_LockRom
#define PduR_GetMmRomIndOfPCConfig()                                                                PduR_MmRomInd
#define PduR_GetMmRomOfPCConfig()                                                                   PduR_MmRom
#define PduR_GetRmDestRomOfPCConfig()                                                               PduR_RmDestRom
#define PduR_GetRmGDestRomOfPCConfig()                                                              PduR_RmGDestRom
#define PduR_GetRmSrcRomOfPCConfig()                                                                PduR_RmSrcRom
#define PduR_GetRmTransmitFctPtrOfPCConfig()                                                        PduR_RmTransmitFctPtr
#define PduR_GetRxTp2DestOfPCConfig()                                                               PduR_RxTp2Dest
#define PduR_GetSizeOfCoreManagerRomOfPCConfig()                                                    1u
#define PduR_GetSizeOfExclusiveAreaRomOfPCConfig()                                                  1u
#define PduR_GetSizeOfLockRomOfPCConfig()                                                           1u
#define PduR_GetSizeOfMmRomIndOfPCConfig()                                                          4u
#define PduR_GetSizeOfMmRomOfPCConfig()                                                             4u
#define PduR_GetSizeOfRmDestRomOfPCConfig()                                                         4u
#define PduR_GetSizeOfRmGDestRomOfPCConfig()                                                        4u
#define PduR_GetSizeOfRmSrcRomOfPCConfig()                                                          4u
#define PduR_GetSizeOfRmTransmitFctPtrOfPCConfig()                                                  2u
#define PduR_GetSizeOfRxTp2DestOfPCConfig()                                                         2u
#define PduR_GetSizeOfTx2LoOfPCConfig()                                                             2u
#define PduR_GetSizeOfTxIf2UpOfPCConfig()                                                           1u
#define PduR_GetSizeOfTxTp2SrcOfPCConfig()                                                          1u
#define PduR_GetTx2LoOfPCConfig()                                                                   PduR_Tx2Lo
#define PduR_GetTxIf2UpOfPCConfig()                                                                 PduR_TxIf2Up
#define PduR_GetTxTp2SrcOfPCConfig()                                                                PduR_TxTp2Src

#define PduR_GetLockOfExclusiveAreaRom(Index)                                                       (PduR_GetExclusiveAreaRomOfPCConfig()[(Index)].LockOfExclusiveAreaRom)
#define PduR_GetUnlockOfExclusiveAreaRom(Index)                                                     (PduR_GetExclusiveAreaRomOfPCConfig()[(Index)].UnlockOfExclusiveAreaRom)
#define PduR_IsInitialized()                                                                        (((*(PduR_GetInitializedOfPCConfig()))) != FALSE)
#define PduR_GetCoreManagerRomIdxOfMmRom(Index)                                                     (PduR_GetMmRomOfPCConfig()[(Index)].CoreManagerRomIdxOfMmRom)
#define PduR_GetLoIfTransmitFctPtrOfMmRom(Index)                                                    (PduR_GetMmRomOfPCConfig()[(Index)].LoIfTransmitFctPtrOfMmRom)
#define PduR_GetLoTpTransmitFctPtrOfMmRom(Index)                                                    (PduR_GetMmRomOfPCConfig()[(Index)].LoTpTransmitFctPtrOfMmRom)
#define PduR_GetMaskedBitsOfMmRom(Index)                                                            (PduR_GetMmRomOfPCConfig()[(Index)].MaskedBitsOfMmRom)
#define PduR_GetRmGDestRomEndIdxOfMmRom(Index)                                                      (PduR_GetMmRomOfPCConfig()[(Index)].RmGDestRomEndIdxOfMmRom)
#define PduR_GetRmGDestRomStartIdxOfMmRom(Index)                                                    (PduR_GetMmRomOfPCConfig()[(Index)].RmGDestRomStartIdxOfMmRom)
#define PduR_GetUpIfRxIndicationFctPtrOfMmRom(Index)                                                (PduR_GetMmRomOfPCConfig()[(Index)].UpIfRxIndicationFctPtrOfMmRom)
#define PduR_GetUpIfTxConfirmationFctPtrOfMmRom(Index)                                              (PduR_GetMmRomOfPCConfig()[(Index)].UpIfTxConfirmationFctPtrOfMmRom)
#define PduR_GetUpTpCopyRxDataFctPtrOfMmRom(Index)                                                  (PduR_GetMmRomOfPCConfig()[(Index)].UpTpCopyRxDataFctPtrOfMmRom)
#define PduR_GetUpTpCopyTxDataFctPtrOfMmRom(Index)                                                  (PduR_GetMmRomOfPCConfig()[(Index)].UpTpCopyTxDataFctPtrOfMmRom)
#define PduR_GetUpTpStartOfReceptionFctPtrOfMmRom(Index)                                            (PduR_GetMmRomOfPCConfig()[(Index)].UpTpStartOfReceptionFctPtrOfMmRom)
#define PduR_GetUpTpTpRxIndicationFctPtrOfMmRom(Index)                                              (PduR_GetMmRomOfPCConfig()[(Index)].UpTpTpRxIndicationFctPtrOfMmRom)
#define PduR_GetUpTpTpTxConfirmationFctPtrOfMmRom(Index)                                            (PduR_GetMmRomOfPCConfig()[(Index)].UpTpTpTxConfirmationFctPtrOfMmRom)
#define PduR_GetRmGDestRomIdxOfRmDestRom(Index)                                                     (PduR_GetRmDestRomOfPCConfig()[(Index)].RmGDestRomIdxOfRmDestRom)
#define PduR_GetRmSrcRomIdxOfRmDestRom(Index)                                                       (PduR_GetRmDestRomOfPCConfig()[(Index)].RmSrcRomIdxOfRmDestRom)
#define PduR_GetRoutingTypeOfRmDestRom(Index)                                                       (PduR_GetRmDestRomOfPCConfig()[(Index)].RoutingTypeOfRmDestRom)
#define PduR_GetDestHndOfRmGDestRom(Index)                                                          (PduR_GetRmGDestRomOfPCConfig()[(Index)].DestHndOfRmGDestRom)
#define PduR_GetDirectionOfRmGDestRom(Index)                                                        (PduR_GetRmGDestRomOfPCConfig()[(Index)].DirectionOfRmGDestRom)
#define PduR_GetMmRomIdxOfRmGDestRom(Index)                                                         (PduR_GetRmGDestRomOfPCConfig()[(Index)].MmRomIdxOfRmGDestRom)
#define PduR_GetPduRDestPduProcessingOfRmGDestRom(Index)                                            (PduR_GetRmGDestRomOfPCConfig()[(Index)].PduRDestPduProcessingOfRmGDestRom)
#define PduR_GetRmDestRomIdxOfRmGDestRom(Index)                                                     (PduR_GetRmGDestRomOfPCConfig()[(Index)].RmDestRomIdxOfRmGDestRom)
#define PduR_GetMmRomIdxOfRmSrcRom(Index)                                                           (PduR_GetRmSrcRomOfPCConfig()[(Index)].MmRomIdxOfRmSrcRom)
#define PduR_GetRmDestRomLengthOfRmSrcRom(Index)                                                    (PduR_GetRmSrcRomOfPCConfig()[(Index)].RmDestRomLengthOfRmSrcRom)
#define PduR_GetRmDestRomStartIdxOfRmSrcRom(Index)                                                  (PduR_GetRmSrcRomOfPCConfig()[(Index)].RmDestRomStartIdxOfRmSrcRom)
#define PduR_GetSrcHndOfRmSrcRom(Index)                                                             (PduR_GetRmSrcRomOfPCConfig()[(Index)].SrcHndOfRmSrcRom)
#define PduR_GetRmTransmitFctPtr(Index)                                                             (PduR_GetRmTransmitFctPtrOfPCConfig()[(Index)])
#define PduR_IsTxConfirmationUsedOfTxIf2Up(Index)                                                   ((PduR_GetTxIf2UpOfPCConfig()[(Index)].TxConfirmationUsedOfTxIf2Up) != FALSE)

#define PduR_IsUpIfOfMmRom(Index)                                                                   (PDUR_UPIFOFMMROM_MASK == (PduR_GetMaskedBitsOfMmRom(Index) & PDUR_UPIFOFMMROM_MASK))

#define PduR_GetConfigId()                                                                          PduR_GetConfigIdOfPCConfig()
#define PduR_GetMmRomIndEndIdxOfCoreManagerRom(Index)                                               ((PduR_MmRomIndEndIdxOfCoreManagerRomType)((((PduR_MmRomIndEndIdxOfCoreManagerRomType)(Index)) + 4u)))
#define PduR_GetMmRomIndStartIdxOfCoreManagerRom(Index)                                             ((PduR_MmRomIndStartIdxOfCoreManagerRomType)((Index)))
#define PduR_IsMmRomIndUsedOfCoreManagerRom(Index)                                                  (((boolean)(PduR_GetMmRomIndStartIdxOfCoreManagerRom(Index) != PDUR_NO_MMROMINDSTARTIDXOFCOREMANAGERROM)) != FALSE)
#define PduR_GetExclusiveAreaRomIdxOfLockRom(Index)                                                 ((PduR_ExclusiveAreaRomIdxOfLockRomType)((Index)))
#define PduR_IsExclusiveAreaRomUsedOfLockRom(Index)                                                 (((boolean)(PduR_GetExclusiveAreaRomIdxOfLockRom(Index) != PDUR_NO_EXCLUSIVEAREAROMIDXOFLOCKROM)) != FALSE)
#define PduR_IsLoIfOfMmRom(Index)                                                                   (((boolean)(PduR_GetMaskedBitsOfMmRom(Index) == 0x14u)) != FALSE)
#define PduR_IsLoTpOfMmRom(Index)                                                                   (((boolean)(PduR_GetMaskedBitsOfMmRom(Index) == 0x0Cu)) != FALSE)
#define PduR_IsRmGDestRomUsedOfMmRom(Index)                                                         (((!(PduR_IsUpIfOfMmRom(Index)))) != FALSE)
#define PduR_IsUpTpOfMmRom(Index)                                                                   (((boolean)(PduR_GetMaskedBitsOfMmRom(Index) == 0x05u)) != FALSE)
#define PduR_GetMmRomInd(Index)                                                                     ((PduR_MmRomIndType)((Index)))
#define PduR_GetLockRomIdxOfRmGDestRom(Index)                                                       ((PduR_LockRomIdxOfRmGDestRomType)((PduR_GetPduRDestPduProcessingOfRmGDestRom(Index) - 0x01u)))
#define PduR_IsRmDestRomUsedOfRmGDestRom(Index)                                                     (((boolean)(PduR_GetRmDestRomIdxOfRmGDestRom(Index) != PDUR_NO_RMDESTROMIDXOFRMGDESTROM)) != FALSE)
#define PduR_GetLockRomIdxOfRmSrcRom(Index)                                                         ((PduR_LockRomIdxOfRmSrcRomType)((PduR_GetRmDestRomLengthOfRmSrcRom(Index) - 1u)))
#define PduR_GetRmDestRomEndIdxOfRmSrcRom(Index)                                                    ((PduR_RmDestRomEndIdxOfRmSrcRomType)((PduR_GetRmDestRomStartIdxOfRmSrcRom(Index) + 1u)))
#define PduR_IsTxConfirmationSupportedOfRmSrcRom(Index)                                             (((boolean)(PduR_GetMmRomIdxOfRmSrcRom(Index) == 3u)) != FALSE)
#define PduR_GetRmSrcRomIdxOfRxTp2Dest(Index)                                                       ((PduR_RmSrcRomIdxOfRxTp2DestType)((Index)))
#define PduR_IsRmSrcRomUsedOfRxTp2Dest(Index)                                                       (((boolean)(PduR_GetRmSrcRomIdxOfRxTp2Dest(Index) != PDUR_NO_RMSRCROMIDXOFRXTP2DEST)) != FALSE)
#define PduR_GetSizeOfCoreManagerRom()                                                              PduR_GetSizeOfCoreManagerRomOfPCConfig()
#define PduR_GetSizeOfExclusiveAreaRom()                                                            PduR_GetSizeOfExclusiveAreaRomOfPCConfig()
#define PduR_GetSizeOfLockRom()                                                                     PduR_GetSizeOfLockRomOfPCConfig()
#define PduR_GetSizeOfMmRom()                                                                       PduR_GetSizeOfMmRomOfPCConfig()
#define PduR_GetSizeOfMmRomInd()                                                                    PduR_GetSizeOfMmRomIndOfPCConfig()
#define PduR_GetSizeOfRmDestRom()                                                                   PduR_GetSizeOfRmDestRomOfPCConfig()
#define PduR_GetSizeOfRmGDestRom()                                                                  PduR_GetSizeOfRmGDestRomOfPCConfig()
#define PduR_GetSizeOfRmSrcRom()                                                                    PduR_GetSizeOfRmSrcRomOfPCConfig()
#define PduR_GetSizeOfRmTransmitFctPtr()                                                            PduR_GetSizeOfRmTransmitFctPtrOfPCConfig()
#define PduR_GetSizeOfRxTp2Dest()                                                                   PduR_GetSizeOfRxTp2DestOfPCConfig()
#define PduR_GetSizeOfTx2Lo()                                                                       PduR_GetSizeOfTx2LoOfPCConfig()
#define PduR_GetSizeOfTxIf2Up()                                                                     PduR_GetSizeOfTxIf2UpOfPCConfig()
#define PduR_GetSizeOfTxTp2Src()                                                                    PduR_GetSizeOfTxTp2SrcOfPCConfig()
#define PduR_GetRmSrcRomIdxOfTx2Lo(Index)                                                           ((PduR_RmSrcRomIdxOfTx2LoType)((((PduR_RmSrcRomIdxOfTx2LoType)(Index)) + 2u)))
#define PduR_IsRmSrcRomUsedOfTx2Lo(Index)                                                           (((boolean)(PduR_GetRmSrcRomIdxOfTx2Lo(Index) != PDUR_NO_RMSRCROMIDXOFTX2LO)) != FALSE)
#define PduR_GetRmTransmitFctPtrIdxOfTx2Lo(Index)                                                   ((PduR_RmTransmitFctPtrIdxOfTx2LoType)((Index)))
#define PduR_GetRmGDestRomIdxOfTxIf2Up(Index)                                                       ((PduR_RmGDestRomIdxOfTxIf2UpType)((Index)))
#define PduR_GetRmGDestRomIdxOfTxTp2Src(Index)                                                      ((PduR_RmGDestRomIdxOfTxTp2SrcType)((((PduR_RmGDestRomIdxOfTxTp2SrcType)(Index)) + 1u)))

#define PduR_SetInitialized(Value)                                                                  (*(PduR_GetInitializedOfPCConfig())) = (Value)

#define PduR_HasConfigId()                                                                          (TRUE != FALSE)
#define PduR_HasCoreManagerRom()                                                                    (TRUE != FALSE)
#define PduR_HasMmRomIndEndIdxOfCoreManagerRom()                                                    (TRUE != FALSE)
#define PduR_HasMmRomIndStartIdxOfCoreManagerRom()                                                  (TRUE != FALSE)
#define PduR_HasMmRomIndUsedOfCoreManagerRom()                                                      (TRUE != FALSE)
#define PduR_HasExclusiveAreaRom()                                                                  (TRUE != FALSE)
#define PduR_HasLockOfExclusiveAreaRom()                                                            (TRUE != FALSE)
#define PduR_HasUnlockOfExclusiveAreaRom()                                                          (TRUE != FALSE)
#define PduR_HasInitialized()                                                                       (TRUE != FALSE)
#define PduR_HasLockRom()                                                                           (TRUE != FALSE)
#define PduR_HasExclusiveAreaRomIdxOfLockRom()                                                      (TRUE != FALSE)
#define PduR_HasExclusiveAreaRomUsedOfLockRom()                                                     (TRUE != FALSE)
#define PduR_HasMmRom()                                                                             (TRUE != FALSE)
#define PduR_HasCoreManagerRomIdxOfMmRom()                                                          (TRUE != FALSE)
#define PduR_HasLoIfOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasLoIfTransmitFctPtrOfMmRom()                                                         (TRUE != FALSE)
#define PduR_HasLoTpOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasLoTpTransmitFctPtrOfMmRom()                                                         (TRUE != FALSE)
#define PduR_HasMaskedBitsOfMmRom()                                                                 (TRUE != FALSE)
#define PduR_HasRmGDestRomEndIdxOfMmRom()                                                           (TRUE != FALSE)
#define PduR_HasRmGDestRomStartIdxOfMmRom()                                                         (TRUE != FALSE)
#define PduR_HasRmGDestRomUsedOfMmRom()                                                             (TRUE != FALSE)
#define PduR_HasUpIfOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasUpIfRxIndicationFctPtrOfMmRom()                                                     (TRUE != FALSE)
#define PduR_HasUpIfTxConfirmationFctPtrOfMmRom()                                                   (TRUE != FALSE)
#define PduR_HasUpTpCopyRxDataFctPtrOfMmRom()                                                       (TRUE != FALSE)
#define PduR_HasUpTpCopyTxDataFctPtrOfMmRom()                                                       (TRUE != FALSE)
#define PduR_HasUpTpOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasUpTpStartOfReceptionFctPtrOfMmRom()                                                 (TRUE != FALSE)
#define PduR_HasUpTpTpRxIndicationFctPtrOfMmRom()                                                   (TRUE != FALSE)
#define PduR_HasUpTpTpTxConfirmationFctPtrOfMmRom()                                                 (TRUE != FALSE)
#define PduR_HasMmRomInd()                                                                          (TRUE != FALSE)
#define PduR_HasRmDestRom()                                                                         (TRUE != FALSE)
#define PduR_HasRmGDestRomIdxOfRmDestRom()                                                          (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfRmDestRom()                                                            (TRUE != FALSE)
#define PduR_HasRoutingTypeOfRmDestRom()                                                            (TRUE != FALSE)
#define PduR_HasRmGDestRom()                                                                        (TRUE != FALSE)
#define PduR_HasDestHndOfRmGDestRom()                                                               (TRUE != FALSE)
#define PduR_HasDirectionOfRmGDestRom()                                                             (TRUE != FALSE)
#define PduR_HasLockRomIdxOfRmGDestRom()                                                            (TRUE != FALSE)
#define PduR_HasMmRomIdxOfRmGDestRom()                                                              (TRUE != FALSE)
#define PduR_HasPduRDestPduProcessingOfRmGDestRom()                                                 (TRUE != FALSE)
#define PduR_HasRmDestRomIdxOfRmGDestRom()                                                          (TRUE != FALSE)
#define PduR_HasRmDestRomUsedOfRmGDestRom()                                                         (TRUE != FALSE)
#define PduR_HasRmSrcRom()                                                                          (TRUE != FALSE)
#define PduR_HasLockRomIdxOfRmSrcRom()                                                              (TRUE != FALSE)
#define PduR_HasMmRomIdxOfRmSrcRom()                                                                (TRUE != FALSE)
#define PduR_HasRmDestRomEndIdxOfRmSrcRom()                                                         (TRUE != FALSE)
#define PduR_HasRmDestRomLengthOfRmSrcRom()                                                         (TRUE != FALSE)
#define PduR_HasRmDestRomStartIdxOfRmSrcRom()                                                       (TRUE != FALSE)
#define PduR_HasSrcHndOfRmSrcRom()                                                                  (TRUE != FALSE)
#define PduR_HasTxConfirmationSupportedOfRmSrcRom()                                                 (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtr()                                                                  (TRUE != FALSE)
#define PduR_HasRxTp2Dest()                                                                         (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfRxTp2Dest()                                                            (TRUE != FALSE)
#define PduR_HasRmSrcRomUsedOfRxTp2Dest()                                                           (TRUE != FALSE)
#define PduR_HasSizeOfCoreManagerRom()                                                              (TRUE != FALSE)
#define PduR_HasSizeOfExclusiveAreaRom()                                                            (TRUE != FALSE)
#define PduR_HasSizeOfLockRom()                                                                     (TRUE != FALSE)
#define PduR_HasSizeOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasSizeOfMmRomInd()                                                                    (TRUE != FALSE)
#define PduR_HasSizeOfRmDestRom()                                                                   (TRUE != FALSE)
#define PduR_HasSizeOfRmGDestRom()                                                                  (TRUE != FALSE)
#define PduR_HasSizeOfRmSrcRom()                                                                    (TRUE != FALSE)
#define PduR_HasSizeOfRmTransmitFctPtr()                                                            (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2Dest()                                                                   (TRUE != FALSE)
#define PduR_HasSizeOfTx2Lo()                                                                       (TRUE != FALSE)
#define PduR_HasSizeOfTxIf2Up()                                                                     (TRUE != FALSE)
#define PduR_HasSizeOfTxTp2Src()                                                                    (TRUE != FALSE)
#define PduR_HasTx2Lo()                                                                             (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfTx2Lo()                                                                (TRUE != FALSE)
#define PduR_HasRmSrcRomUsedOfTx2Lo()                                                               (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtrIdxOfTx2Lo()                                                        (TRUE != FALSE)
#define PduR_HasTxIf2Up()                                                                           (TRUE != FALSE)
#define PduR_HasRmGDestRomIdxOfTxIf2Up()                                                            (TRUE != FALSE)
#define PduR_HasTxConfirmationUsedOfTxIf2Up()                                                       (TRUE != FALSE)
#define PduR_HasTxTp2Src()                                                                          (TRUE != FALSE)
#define PduR_HasRmGDestRomIdxOfTxTp2Src()                                                           (TRUE != FALSE)
#define PduR_HasPCConfig()                                                                          (TRUE != FALSE)
#define PduR_HasConfigIdOfPCConfig()                                                                (TRUE != FALSE)
#define PduR_HasCoreManagerRomOfPCConfig()                                                          (TRUE != FALSE)
#define PduR_HasExclusiveAreaRomOfPCConfig()                                                        (TRUE != FALSE)
#define PduR_HasInitializedOfPCConfig()                                                             (TRUE != FALSE)
#define PduR_HasLockRomOfPCConfig()                                                                 (TRUE != FALSE)
#define PduR_HasMmRomIndOfPCConfig()                                                                (TRUE != FALSE)
#define PduR_HasMmRomOfPCConfig()                                                                   (TRUE != FALSE)
#define PduR_HasRmDestRomOfPCConfig()                                                               (TRUE != FALSE)
#define PduR_HasRmGDestRomOfPCConfig()                                                              (TRUE != FALSE)
#define PduR_HasRmSrcRomOfPCConfig()                                                                (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtrOfPCConfig()                                                        (TRUE != FALSE)
#define PduR_HasRxTp2DestOfPCConfig()                                                               (TRUE != FALSE)
#define PduR_HasSizeOfCoreManagerRomOfPCConfig()                                                    (TRUE != FALSE)
#define PduR_HasSizeOfExclusiveAreaRomOfPCConfig()                                                  (TRUE != FALSE)
#define PduR_HasSizeOfLockRomOfPCConfig()                                                           (TRUE != FALSE)
#define PduR_HasSizeOfMmRomIndOfPCConfig()                                                          (TRUE != FALSE)
#define PduR_HasSizeOfMmRomOfPCConfig()                                                             (TRUE != FALSE)
#define PduR_HasSizeOfRmDestRomOfPCConfig()                                                         (TRUE != FALSE)
#define PduR_HasSizeOfRmGDestRomOfPCConfig()                                                        (TRUE != FALSE)
#define PduR_HasSizeOfRmSrcRomOfPCConfig()                                                          (TRUE != FALSE)
#define PduR_HasSizeOfRmTransmitFctPtrOfPCConfig()                                                  (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2DestOfPCConfig()                                                         (TRUE != FALSE)
#define PduR_HasSizeOfTx2LoOfPCConfig()                                                             (TRUE != FALSE)
#define PduR_HasSizeOfTxIf2UpOfPCConfig()                                                           (TRUE != FALSE)
#define PduR_HasSizeOfTxTp2SrcOfPCConfig()                                                          (TRUE != FALSE)
#define PduR_HasTx2LoOfPCConfig()                                                                   (TRUE != FALSE)
#define PduR_HasTxIf2UpOfPCConfig()                                                                 (TRUE != FALSE)
#define PduR_HasTxTp2SrcOfPCConfig()                                                                (TRUE != FALSE)

typedef P2FUNC(void, PDUR_CODE, PduR_LockFunctionType) (void);		

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TransmitFctPtrType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));		
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TriggerTransmitFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));		
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfRxIndicationType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));		
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfTxConfirmationFctPtrType) (PduIdType);		

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_StartOfReceptionFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), PduLengthType, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));		

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyRxDataFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));		

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyTxDataFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));		

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpRxIndicationFctPtrType) (PduIdType, Std_ReturnType);		

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpTxConfirmationFctPtrType) (PduIdType, Std_ReturnType);		

#if((PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON) || (PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON))
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CancelTransmitFctPtrType)(PduIdType);		
#endif
#if(PDUR_CANCELRECEIVESUPPORTEDOFMMROM == STD_ON)
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CancelReceiveFctPtrType) (PduIdType);		
#endif
#if(PDUR_CHANGEPARAMETERSUPPORTEDOFMMROM == STD_ON)
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_ChangeParameterFctPtrType) (PduIdType, TPParameterType, uint16);		
#endif

typedef P2FUNC(void, PDUR_CODE, PduR_DisableRoutingFctPtrType) (PduR_RoutingPathGroupIdType);		

typedef uint8_least PduR_CoreManagerRomIterType;

typedef uint8_least PduR_ExclusiveAreaRomIterType;

typedef uint8_least PduR_LockRomIterType;

typedef uint8_least PduR_MmRomIterType;

typedef uint8_least PduR_MmRomIndIterType;

typedef uint8_least PduR_RmDestRomIterType;

typedef uint8_least PduR_RmGDestRomIterType;

typedef uint8_least PduR_RmSrcRomIterType;

typedef uint8_least PduR_RmTransmitFctPtrIterType;

typedef uint8_least PduR_RxTp2DestIterType;

typedef uint8_least PduR_Tx2LoIterType;

typedef uint8_least PduR_TxIf2UpIterType;

typedef uint8_least PduR_TxTp2SrcIterType;

typedef uint8 PduR_ConfigIdType;

typedef uint8 PduR_MmRomIndEndIdxOfCoreManagerRomType;

typedef uint8 PduR_MmRomIndStartIdxOfCoreManagerRomType;

typedef boolean PduR_MmRomIndUsedOfCoreManagerRomType;

typedef boolean PduR_InitializedType;

typedef uint8 PduR_ExclusiveAreaRomIdxOfLockRomType;

typedef boolean PduR_ExclusiveAreaRomUsedOfLockRomType;

typedef uint8 PduR_CoreManagerRomIdxOfMmRomType;

typedef boolean PduR_LoIfOfMmRomType;

typedef boolean PduR_LoTpOfMmRomType;

typedef uint8 PduR_MaskedBitsOfMmRomType;

typedef uint8 PduR_RmGDestRomEndIdxOfMmRomType;

typedef uint8 PduR_RmGDestRomStartIdxOfMmRomType;

typedef boolean PduR_RmGDestRomUsedOfMmRomType;

typedef boolean PduR_UpIfOfMmRomType;

typedef boolean PduR_UpTpOfMmRomType;

typedef uint8 PduR_MmRomIndType;

typedef uint8 PduR_RmGDestRomIdxOfRmDestRomType;

typedef uint8 PduR_RmSrcRomIdxOfRmDestRomType;

typedef uint8 PduR_RoutingTypeOfRmDestRomType;

typedef uint8 PduR_DestHndOfRmGDestRomType;

typedef uint8 PduR_DirectionOfRmGDestRomType;

typedef uint8 PduR_LockRomIdxOfRmGDestRomType;

typedef uint8 PduR_MmRomIdxOfRmGDestRomType;

typedef uint8 PduR_PduRDestPduProcessingOfRmGDestRomType;

typedef uint8 PduR_RmDestRomIdxOfRmGDestRomType;

typedef boolean PduR_RmDestRomUsedOfRmGDestRomType;

typedef uint8 PduR_LockRomIdxOfRmSrcRomType;

typedef uint8 PduR_MmRomIdxOfRmSrcRomType;

typedef uint8 PduR_RmDestRomEndIdxOfRmSrcRomType;

typedef uint8 PduR_RmDestRomLengthOfRmSrcRomType;

typedef uint8 PduR_RmDestRomStartIdxOfRmSrcRomType;

typedef uint8 PduR_SrcHndOfRmSrcRomType;

typedef boolean PduR_TxConfirmationSupportedOfRmSrcRomType;

typedef uint8 PduR_RmSrcRomIdxOfRxTp2DestType;

typedef boolean PduR_RmSrcRomUsedOfRxTp2DestType;

typedef uint8 PduR_SizeOfCoreManagerRomType;

typedef uint8 PduR_SizeOfExclusiveAreaRomType;

typedef uint8 PduR_SizeOfLockRomType;

typedef uint8 PduR_SizeOfMmRomType;

typedef uint8 PduR_SizeOfMmRomIndType;

typedef uint8 PduR_SizeOfRmDestRomType;

typedef uint8 PduR_SizeOfRmGDestRomType;

typedef uint8 PduR_SizeOfRmSrcRomType;

typedef uint8 PduR_SizeOfRmTransmitFctPtrType;

typedef uint8 PduR_SizeOfRxTp2DestType;

typedef uint8 PduR_SizeOfTx2LoType;

typedef uint8 PduR_SizeOfTxIf2UpType;

typedef uint8 PduR_SizeOfTxTp2SrcType;

typedef uint8 PduR_RmSrcRomIdxOfTx2LoType;

typedef boolean PduR_RmSrcRomUsedOfTx2LoType;

typedef uint8 PduR_RmTransmitFctPtrIdxOfTx2LoType;

typedef uint8 PduR_RmGDestRomIdxOfTxIf2UpType;

typedef boolean PduR_TxConfirmationUsedOfTxIf2UpType;

typedef uint8 PduR_RmGDestRomIdxOfTxTp2SrcType;

#if(PDUR_RMSRCROM == STD_ON)
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_RmTransmitFctPtrType) (PduR_RmSrcRomIterType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));		
#endif
#if(PDUR_RMDESTROM == STD_ON)
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_RmIfRxIndicationType) (PduR_RmDestRomIterType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));		
#endif

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_QAL_PutFctPtrType)          (PduR_RmGDestRomIterType, PduR_RmDestRomIterType, PduLengthType, SduDataPtrType);
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_QAL_GetFctPtrType)          (PduR_RmGDestRomIterType, P2VAR(PduR_RmDestRomIterType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(void,           PDUR_APPL_CODE, PduR_QAL_RemoveFctPtrType)       (PduR_RmGDestRomIterType);
typedef P2FUNC(uint16,         PDUR_APPL_CODE, PduR_QAL_GetFillLevelFctPtrType) (PduR_RmGDestRomIterType);
typedef P2FUNC(void,           PDUR_APPL_CODE, PduR_QAL_FlushFctPtrType)        (PduR_RmGDestRomIterType);

typedef P2FUNC(void, PDUR_CODE, PduR_RmIf_TxConfirmation_StateHandler_FctPtrType) (PduR_RmGDestRomIterType);		
typedef P2FUNC(void, PDUR_CODE, PduR_RmIf_FifoHandling_StateHandler_FctPtrType) (PduR_RmDestRomIterType, PduR_RmGDestRomIdxOfRmDestRomType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));		

#if(PDUR_FMFIFORAM == STD_ON)
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_StartOfReceptionFifoSmFctPtrType) (PduR_RmSrcRomIterType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), PduLengthType, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));		
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyRxDataFifoSmFctPtrType) (PduR_RmSrcRomIterType, PduLengthType, SduDataPtrType, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));		
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpRxIndicationFifoSmFctPtrType) (PduR_RmSrcRomIterType, Std_ReturnType);		
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpCancelReceiveFctPtrType) (PduR_RmSrcRomIterType);		

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyTxDataFifoSmFctPtrType) (PduR_RmGDestRomIterType, PduLengthType, SduDataPtrType, P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));		
typedef PduR_CopyTxDataFifoSmFctPtrType PduR_CopyTxDataFifoSmFctPtrArrayType[2];		
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TpTriggerTransmitFctPtrType) (PduR_RmDestRomIterType, PduR_RmGDestRomIterType);		
typedef PduR_TpTriggerTransmitFctPtrType PduR_TpTriggerTransmitFctPtrArrayType[2];		
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpTxConfirmationFifoSmFctPtrType) (PduR_RmGDestRomIterType, Std_ReturnType);		
typedef PduR_TpTxConfirmationFifoSmFctPtrType PduR_TpTxConfirmationFifoSmFctPtrArrayType[2];		
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TpCancelTransmitFctPtrType)(PduR_RmDestRomIterType);		
typedef PduR_TpCancelTransmitFctPtrType PduR_TpCancelTransmitFctPtrArrayType[2];		
typedef P2FUNC(void, PDUR_CODE, PduR_TpDisableRoutingFctPtrType) (PduR_RmGDestRomIterType);		

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CheckReady2TransmitFctPtrType) (PduR_RmSrcRomIterType);		

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_FinishReceptionFctPtrType) (PduR_RmSrcRomIterType, Std_ReturnType);		

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_FinishTransmissionFctPtrType) (PduR_RmSrcRomIterType, Std_ReturnType);		

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_ActivateNextFctPtrType) (PduR_FmFifoElementRamIterType, Std_ReturnType);		
#endif

#if((PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM  == STD_ON) || (PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM  == STD_ON))
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_FinishReadFctPtrType) (PduR_FmFifoElementRamIterType, Std_ReturnType);		
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_FinishWriteFctPtrType) (PduR_FmFifoElementRamIterType, Std_ReturnType);		
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_ActivateReadFctPtrType) (PduR_FmFifoElementRamIterType);		
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_ActivateWriteFctPtrType) (PduR_FmFifoElementRamIterType);		
#endif

#if(PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM == STD_ON)
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_Fm_FlushFiFoElementPtrType) (PduR_FmFifoElementRamIterType);		
#endif

#if(PDUR_SMDATAPLANEROM == STD_ON)
typedef uint8 PduR_FilterReturnType;
# define PDUR_FILTER_PASS  0u
# define PDUR_FILTER_BLOCK 1u

typedef uint32 PduR_SmSaType;
typedef uint32 PduR_SmTaType;

#define PDUR_SM_UNLEARNED_CONNECTION 0u
typedef P2FUNC(PduR_SmSaType, PDUR_CODE, PduR_Sm_LinearTaToSaCalculationStrategy_GetSaFctPtrType) (PduR_SmLinearTaToSaCalculationStrategyRomIterType, uint32);		
typedef P2FUNC(void, PDUR_CODE, PduR_Sm_SrcFilterFctPtrType) (PduR_SmSrcRomIdxOfRmSrcRomType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));		
typedef P2FUNC(PduR_FilterReturnType, PDUR_CODE, PduR_Sm_DestFilterFctPtrType) (PduR_SmGDestRomIdxOfRmGDestRomType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));		
#endif

typedef struct sPduR_CoreManagerRomType{
  uint8 PduR_CoreManagerRomNeverUsed;
}PduR_CoreManagerRomType;

typedef struct sPduR_ExclusiveAreaRomType{
  PduR_LockFunctionType LockOfExclusiveAreaRom;
  PduR_LockFunctionType UnlockOfExclusiveAreaRom;
}PduR_ExclusiveAreaRomType;

typedef struct sPduR_LockRomType{
  uint8 PduR_LockRomNeverUsed;
}PduR_LockRomType;

typedef struct sPduR_MmRomType{
  PduR_CoreManagerRomIdxOfMmRomType CoreManagerRomIdxOfMmRom;
  PduR_MaskedBitsOfMmRomType MaskedBitsOfMmRom;
  PduR_RmGDestRomEndIdxOfMmRomType RmGDestRomEndIdxOfMmRom;
  PduR_RmGDestRomStartIdxOfMmRomType RmGDestRomStartIdxOfMmRom;
  PduR_CopyRxDataFctPtrType UpTpCopyRxDataFctPtrOfMmRom;
  PduR_CopyTxDataFctPtrType UpTpCopyTxDataFctPtrOfMmRom;
  PduR_IfRxIndicationType UpIfRxIndicationFctPtrOfMmRom;
  PduR_IfTxConfirmationFctPtrType UpIfTxConfirmationFctPtrOfMmRom;
  PduR_StartOfReceptionFctPtrType UpTpStartOfReceptionFctPtrOfMmRom;
  PduR_TpRxIndicationFctPtrType UpTpTpRxIndicationFctPtrOfMmRom;
  PduR_TpTxConfirmationFctPtrType UpTpTpTxConfirmationFctPtrOfMmRom;
  PduR_TransmitFctPtrType LoIfTransmitFctPtrOfMmRom;
  PduR_TransmitFctPtrType LoTpTransmitFctPtrOfMmRom;
}PduR_MmRomType;

typedef struct sPduR_RmDestRomType{
  PduR_RmGDestRomIdxOfRmDestRomType RmGDestRomIdxOfRmDestRom;
  PduR_RmSrcRomIdxOfRmDestRomType RmSrcRomIdxOfRmDestRom;
  PduR_RoutingTypeOfRmDestRomType RoutingTypeOfRmDestRom;
}PduR_RmDestRomType;

typedef struct sPduR_RmGDestRomType{
  PduR_DestHndOfRmGDestRomType DestHndOfRmGDestRom;
  PduR_DirectionOfRmGDestRomType DirectionOfRmGDestRom;
  PduR_MmRomIdxOfRmGDestRomType MmRomIdxOfRmGDestRom;
  PduR_PduRDestPduProcessingOfRmGDestRomType PduRDestPduProcessingOfRmGDestRom;
  PduR_RmDestRomIdxOfRmGDestRomType RmDestRomIdxOfRmGDestRom;
}PduR_RmGDestRomType;

typedef struct sPduR_RmSrcRomType{
  PduR_MmRomIdxOfRmSrcRomType MmRomIdxOfRmSrcRom;
  PduR_RmDestRomLengthOfRmSrcRomType RmDestRomLengthOfRmSrcRom;
  PduR_RmDestRomStartIdxOfRmSrcRomType RmDestRomStartIdxOfRmSrcRom;
  PduR_SrcHndOfRmSrcRomType SrcHndOfRmSrcRom;
}PduR_RmSrcRomType;

typedef struct sPduR_RxTp2DestType{
  uint8 PduR_RxTp2DestNeverUsed;
}PduR_RxTp2DestType;

typedef struct sPduR_Tx2LoType{
  uint8 PduR_Tx2LoNeverUsed;
}PduR_Tx2LoType;

typedef struct sPduR_TxIf2UpType{
  PduR_TxConfirmationUsedOfTxIf2UpType TxConfirmationUsedOfTxIf2Up;
}PduR_TxIf2UpType;

typedef struct sPduR_TxTp2SrcType{
  uint8 PduR_TxTp2SrcNeverUsed;
}PduR_TxTp2SrcType;

typedef P2CONST(PduR_CoreManagerRomType, TYPEDEF, PDUR_CONST) PduR_CoreManagerRomPtrType;

typedef P2CONST(PduR_ExclusiveAreaRomType, TYPEDEF, PDUR_CONST) PduR_ExclusiveAreaRomPtrType;

typedef P2VAR(PduR_InitializedType, TYPEDEF, PDUR_VAR_ZERO_INIT) PduR_InitializedPtrType;

typedef P2CONST(PduR_LockRomType, TYPEDEF, PDUR_CONST) PduR_LockRomPtrType;

typedef P2CONST(PduR_MmRomType, TYPEDEF, PDUR_CONST) PduR_MmRomPtrType;

typedef P2CONST(PduR_MmRomIndType, TYPEDEF, PDUR_CONST) PduR_MmRomIndPtrType;

typedef P2CONST(PduR_RmDestRomType, TYPEDEF, PDUR_CONST) PduR_RmDestRomPtrType;

typedef P2CONST(PduR_RmGDestRomType, TYPEDEF, PDUR_CONST) PduR_RmGDestRomPtrType;

typedef P2CONST(PduR_RmSrcRomType, TYPEDEF, PDUR_CONST) PduR_RmSrcRomPtrType;

typedef P2CONST(PduR_RmTransmitFctPtrType, TYPEDEF, PDUR_CONST) PduR_RmTransmitFctPtrPtrType;

typedef P2CONST(PduR_RxTp2DestType, TYPEDEF, PDUR_CONST) PduR_RxTp2DestPtrType;

typedef P2CONST(PduR_Tx2LoType, TYPEDEF, PDUR_CONST) PduR_Tx2LoPtrType;

typedef P2CONST(PduR_TxIf2UpType, TYPEDEF, PDUR_CONST) PduR_TxIf2UpPtrType;

typedef P2CONST(PduR_TxTp2SrcType, TYPEDEF, PDUR_CONST) PduR_TxTp2SrcPtrType;

typedef struct sPduR_PCConfigType{
  uint8 PduR_PCConfigNeverUsed;
}PduR_PCConfigType;

typedef PduR_PCConfigType PduR_PBConfigType;

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(PduR_ExclusiveAreaRomType, PDUR_CONST) PduR_ExclusiveAreaRom[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(PduR_MmRomType, PDUR_CONST) PduR_MmRom[4];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRom[4];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRom[4];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRom[4];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(PduR_RmTransmitFctPtrType, PDUR_CONST) PduR_RmTransmitFctPtr[2];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(PduR_TxIf2UpType, PDUR_CONST) PduR_TxIf2Up[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_VAR_ZERO_INIT_8BIT

#include "MemMap.hpp"

extern VAR(PduR_InitializedType, PDUR_VAR_ZERO_INIT) PduR_Initialized;
#define PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT

#include "MemMap.hpp"

#define PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.hpp"

#if(PDUR_USE_INIT_POINTER == STD_ON)
extern P2CONST(PduR_PBConfigType, PDUR_VAR_ZERO_INIT, PDUR_PBCFG) PduR_ConfigDataPtr;
#endif

#define PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.hpp"

#endif

