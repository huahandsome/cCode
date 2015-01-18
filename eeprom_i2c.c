#define PROC_ENTRY_NAME "eeprom_test"

/* Addresses to scan */
static unsigned short normal_i2c[] = { /* ?????? Address need to be filled*/, I2C_CLIENT_END };

/*
 eeprom_i2c_id_table
*/

/**************/
/* I2C Driver */
/**************/
static struct i2c_driver eeprom_driver = {
    .driver = {
        .name    = "gpon_i2c",
    },
    .attach_adapter   = eeprom_attach_adapter, 
    .detach_client    = eeprom_detach_client,  
};


struct proc_dir_entry *p_eeprom = NULL;

/**************************************************/
/*              Functions definition              */
/**************************************************/

static int eeprom_attach_adapter(struct i2c_adapter *adapter)
{
   return i2c_probe(adapter, &addr_data, eeprom_detect);}
}


