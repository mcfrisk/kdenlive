install(FILES banner.png timeline_nothumbs.png timeline_athumbs.png timeline_vthumbs.png timeline_avthumbs.png metadata.properties blacklisted_effects.txt blacklisted_transitions.txt encodingprofiles.rc DESTINATION ${DATA_INSTALL_DIR}/kdenlive )
install( FILES kdenliveeffectscategory.rc DESTINATION  ${CONFIG_INSTALL_DIR} )
install (FILES kdenlive.xpm DESTINATION share/pixmaps)
install (FILES kdenlive.menu DESTINATION share/menu RENAME kdenlive)
